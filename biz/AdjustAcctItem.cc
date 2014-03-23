#include "AdjustAcctItem.hh"
#include "libconfparser/confparser.hpp"

AdjustAcctItem::AdjustAcctItem(LoggerId logId)
{
    m_logId = logId;
    LOG_DEBUG(m_logId, "AdjustAcctItem::AdjustAcctItem start");

    LOG_DEBUG(logId, "Parse boss.cfg");
    CONF_PARSER_SIMPLE_INIT("../conf/boss.cfg");
    string db_user = CONF_PARSER_GET_VAL("DB", "user");
    string db_passwd = CONF_PARSER_GET_VAL("DB", "passwd");
    string db_instance = CONF_PARSER_GET_VAL("DB", "instance");
    LOG_DEBUG(logId, "DB User:"<<db_user);
    LOG_DEBUG(logId, "DB Passwd:"<<db_passwd);
    LOG_DEBUG(logId, "DB Instance:"<<db_instance);

    m_db = new OracleDB(db_user,db_passwd,db_instance);
    m_db->connectToDB();

    int zmq_pub_port = CONF_PARSER_GET_NUM_VAL("AdjustAcctItem", "zmq_pub_port");
    LOG_INFO(logId, "Server zmq_pub_port:"<<zmq_pub_port);

    context = new context_t(1);
    socket = new socket_t(*context,ZMQ_PUB);

    char bind_str[20];
    sprintf(bind_str,"tcp://*:%d",zmq_pub_port);
    socket->bind(bind_str);

    loadConfigData();

    m_seq.setConnection(m_db->getConnection());

    LOG_DEBUG(m_logId, "AdjustAcctItem::AdjustAcctItem end");
}

AdjustAcctItem::~AdjustAcctItem()
{
    LOG_DEBUG(m_logId, "AdjustAcctItem::~AdjustAcctItem start");
    m_db->disConnectFromDB();
    LOG_DEBUG(m_logId, "AdjustAcctItem::~AdjustAcctItem end");
}

void AdjustAcctItem::loadConfigData()
{
    LOG_DEBUG(m_logId, "AdjustAcctItem::loadConfigData start");
    BillingCycle m_billing_cycle;
    Staff m_staff;
    Region m_region;
    AcctItemType m_acct_item_type;

    m_billing_cycle.setConnection(m_db->getConnection());
    m_staff.setConnection(m_db->getConnection());
    m_region.setConnection(m_db->getConnection());
    m_acct_item_type.setConnection(m_db->getConnection());

    v_billing_cycle = m_billing_cycle.loadAllData();
    v_staff = m_staff.loadAllData();
    v_region = m_region.loadAllData();
    v_acct_item_type = m_acct_item_type.loadAllData();
    LOG_DEBUG(m_logId, "AdjustAcctItem::loadConfigData end");
}

void AdjustAcctItem::doBiz(AdjustAcctItemData & data)
{
    try
    {
        LOG_DEBUG(m_logId, "AdjustAcctItem::doBiz start");
        long billing_cycle_id = v_billing_cycle[rand()%v_billing_cycle.size()].m_billing_cycle_id;
        long staff_id = v_staff[rand()%v_staff.size()].m_staff_id;
        long region_id = v_region[rand()%v_region.size()].m_region_id;
        long acct_item_type_id = v_acct_item_type[rand()%v_acct_item_type.size()].m_acct_item_type_id;

        LOG_INFO(m_logId, "Billing_cycle_id:"<<billing_cycle_id);
        LOG_INFO(m_logId, "Staff_id :"<<staff_id);
        LOG_INFO(m_logId, "Region_id:"<<region_id);

        //get serv_identification info
        ServIdentification m_serv_ident;
        m_serv_ident.setConnection(m_db->getConnection());
        ST_SERV_IDENTIFICATION serv_ident_info;
        if(data.nbr != "")
        {
            LOG_INFO(m_logId, "AdjustAcctItem::doBiz input nbr:"<<data.nbr);
            serv_ident_info = m_serv_ident.getServIdentInfoByNBR(data.nbr);
        }
        else
        {
            LOG_INFO(m_logId, "AdjustAcctItem::doBiz no input nbr, system will select a random nbr to do payment.");
            serv_ident_info = m_serv_ident.getRandomServIdentInfo();
            LOG_INFO(m_logId, "AdjustAcctItem::doBiz the random nbr:"<<serv_ident_info.m_acc_nbr);
        }

        //cerr<<serv_ident_info.m_acc_nbr<<":"<<m_serv_ident.serv_identification.m_serv_id<<endl;
        long serv_id = m_serv_ident.serv_identification.m_serv_id;

        if(data.fee < 0.01)
          data.fee = 100; //use the default value 100;

        if(data.ym == "")
        {
            Dual dual;
            dual.setConnection(m_db->getConnection());
            data.ym = dual.getSysDateYYYYMM();
        }


        LOG_INFO(m_logId, "AdjustAcctItem::doBiz get serv_acct info");
        ServAcct m_serv_acct;
        m_serv_acct.setConnection(m_db->getConnection());
        ST_SERV_ACCT serv_acct_data = m_serv_acct.getServAcctByServId(serv_id);
        long acct_id = serv_acct_data.m_acct_id;

        LOG_INFO(m_logId, "AdjustAcctItem::doBiz update acct info");
        Acct m_acct;
        m_acct.setConnection(m_db->getConnection());
        ST_ACCT acct_data = m_acct.getAcctByAcctId(acct_id);
        LOG_INFO(m_logId, "AdjustAcctItem::doBiz acct_id:"<<acct_id<<" old owe_min_ym:"<<acct_data.m_owe_min_ym<<" old owe_fee:"<<acct_data.m_owe_fee);
        long ym = atol(data.ym.c_str());
        if(ym>acct_data.m_owe_min_ym) ym = acct_data.m_owe_min_ym;
        long fee = acct_data.m_owe_fee+(int)(data.fee*100);
        LOG_INFO(m_logId, "AdjustAcctItem::doBiz acct_id:"<<acct_id<<" new owe_min_ym:"<<ym<<" new owe_fee:"<<fee);
        m_acct.setAcctOweMinYMAndOweFee(acct_id,ym,fee);

        LOG_INFO(m_logId, "AdjustAcctItem::doBiz insert to ACCT_ITEM_SOURCE table");
        AcctItemSource m_acct_item_source;
        m_acct_item_source.setConnection(m_db->getConnection());
        long item_source_id=m_seq.getItemSourceId();
        m_acct_item_source.acct_item_source.m_item_source_id=item_source_id;
        m_acct_item_source.acct_item_source.m_acct_item_type_id=acct_item_type_id;
        m_acct_item_source.acct_item_source.m_item_source_type="52A";
        m_acct_item_source.acct_item_source.m_name="帐目应收费用";
        m_acct_item_source.acct_item_source.m_comments="新增";
        m_acct_item_source.insertData();

        LOG_INFO(m_logId, "AdjustAcctItem::doBiz insert to acct_item table");
        AcctItem m_acct_item;
        m_acct_item.setConnection(m_db->getConnection());
        if(data.ym != "")
        {
            m_acct_item.setYM(data.ym);
        }
        long acct_item_id=m_seq.getAcctItemId();
        m_acct_item.acct_item.m_acct_item_id=acct_item_id;
        m_acct_item.acct_item.m_item_source_id=item_source_id;
        m_acct_item.acct_item.m_bill_id=0;
        m_acct_item.acct_item.m_acct_item_type_id=acct_item_type_id;
        m_acct_item.acct_item.m_billing_cycle_id=billing_cycle_id;
        m_acct_item.acct_item.m_acct_id=acct_id;
        m_acct_item.acct_item.m_serv_id=serv_id;
        m_acct_item.acct_item.m_amount=(int)(data.fee*100);
        m_acct_item.acct_item.m_fee_cycle_id=billing_cycle_id;
        m_acct_item.acct_item.m_payment_method=0;
        m_acct_item.acct_item.m_state="00A";
        m_acct_item.acct_item.m_latn_id=region_id;
        m_acct_item.acct_item.m_ai_total_id=0;
        m_acct_item.acct_item.m_acc_nbr=serv_ident_info.m_acc_nbr;
        m_acct_item.acct_item.m_should_pay=(int)(data.fee*100);
        m_acct_item.acct_item.m_favour_fee=0;
        m_acct_item.acct_item.m_times=0;
        m_acct_item.acct_item.m_duration=0;
        m_acct_item.acct_item.m_month_wrtoff_fee=0;
        m_acct_item.acct_item.m_pay_wrtoff_fee=0;
        m_acct_item.acct_item.m_attr_code="";
        m_acct_item.insertData();

        LOG_INFO(m_logId, "AdjustAcctItem::doBiz insert to ACCT_ITEM_ADJUSTED table");
        AcctItemAdjusted m_acct_item_adjusted;
        m_acct_item_adjusted.setConnection(m_db->getConnection());
        long adjust_record_id = m_seq.getAdjustRecordId();
        m_acct_item_adjusted.acct_item_adjusted.m_adjust_record_id=adjust_record_id;
        m_acct_item_adjusted.acct_item_adjusted.m_acct_item_id=acct_item_id;
        m_acct_item_adjusted.acct_item_adjusted.m_adjust_acct_item_id=0;
        m_acct_item_adjusted.acct_item_adjusted.m_charge_adjust=(int)(data.fee*100);
        m_acct_item_adjusted.insertData();

        LOG_INFO(m_logId, "AdjustAcctItem::doBiz insert to CHARGE_ADJUST_LOG table");
        ChargeAdjustLog m_charge_adjust_log;
        m_charge_adjust_log.setConnection(m_db->getConnection());
        m_charge_adjust_log.charge_adjust_log.m_charge_adjust_log_id=m_seq.getChargeAdjustLogId();
        m_charge_adjust_log.charge_adjust_log.m_adjust_record_id=adjust_record_id;
        m_charge_adjust_log.charge_adjust_log.m_cause="自动生成数据";
        m_charge_adjust_log.charge_adjust_log.m_staff_id=staff_id;
        m_charge_adjust_log.insertData();

        LOG_INFO(m_logId, "AdjustAcctItem::doBiz insert to staff_opr table");
        StaffOpr m_staff_opr;
        m_staff_opr.setConnection(m_db->getConnection());
        m_staff_opr.staff_opr.m_login_accept = m_seq.getScardvcsn();
        m_staff_opr.staff_opr.m_op_code = "TZ";
        m_staff_opr.staff_opr.m_payment_method = 0;
        m_staff_opr.staff_opr.m_pay_money = (int)(100*data.fee);
        m_staff_opr.staff_opr.m_band_id = 111;
        m_staff_opr.staff_opr.m_serv_id = serv_id;
        m_staff_opr.staff_opr.m_acc_nbr = serv_ident_info.m_acc_nbr;
        m_staff_opr.staff_opr.m_op_note = "调帐";
        m_staff_opr.staff_opr.m_ip_addr = "127.0.0.1";
        m_staff_opr.staff_opr.m_staff_org_id = region_id;
        m_staff_opr.staff_opr.m_nbr_org_id = region_id;
        m_staff_opr.staff_opr.m_staff_id = staff_id;
        m_staff_opr.insertData();

        //begin publish
        char* filter = (char*)"TZ ";
        char buf[64];
        snprintf(buf, sizeof(buf), "%s%s", filter,serv_ident_info.m_acc_nbr.c_str());

        message_t request(strlen(buf)+1);
        memcpy ((void *) request.data (), buf, strlen(buf)+1);
        socket->send(request);
            
        m_db->commit();

        LOG_DEBUG(m_logId, "AdjustAcctItem::doBiz end");
    }
    catch(...)
    {
        LOG_ERROR(m_logId, "AdjustAcctItem::doBiz error");
        m_db->rollback();
    }
}


