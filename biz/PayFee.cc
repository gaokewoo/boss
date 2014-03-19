#include "PayFee.hh"
#include "libconfparser/confparser.hpp"
#include "ServIdentification.hh"

PayFee::PayFee(LoggerId logId)
{
    m_logId = logId;
    LOG_DEBUG(m_logId, "PayFee::PayFee start");

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

    loadConfigData();

    m_seq.setConnection(m_db->getConnection());

    LOG_DEBUG(m_logId, "PayFee::PayFee end");
}

PayFee::~PayFee()
{
    LOG_DEBUG(m_logId, "PayFee::~PayFee start");
    m_db->disConnectFromDB();
    LOG_DEBUG(m_logId, "PayFee::~PayFee end");
}

void PayFee::loadConfigData()
{
    LOG_DEBUG(m_logId, "PayFee::loadConfigData start");
    PaymentMethod m_payment_method;
    BalanceSourceType m_balance_source_type;
    BalanceType m_balance_type;
    BillingCycle m_billing_cycle;
    Staff m_staff;
    Region m_region;

    m_payment_method.setConnection(m_db->getConnection());
    m_balance_source_type.setConnection(m_db->getConnection());
    m_balance_type.setConnection(m_db->getConnection());
    m_billing_cycle.setConnection(m_db->getConnection());
    m_staff.setConnection(m_db->getConnection());
    m_region.setConnection(m_db->getConnection());

    v_payment_method = m_payment_method.loadAllData();
    v_balance_source_type = m_balance_source_type.loadAllData();
    v_balance_type = m_balance_type.loadAllData();
    v_billing_cycle = m_billing_cycle.loadAllData();
    v_staff = m_staff.loadAllData();
    v_region = m_region.loadAllData();
    LOG_DEBUG(m_logId, "PayFee::loadConfigData end");
}

void PayFee::doBiz(PayFeeData & data)
{
    try
    {
        LOG_DEBUG(m_logId, "PayFee::doBiz start");

        ST_PAYMENT_METHOD l_payment_method = v_payment_method[rand()%v_payment_method.size()];
        long payment_method = l_payment_method.m_payment_method;
        long balance_type_id = l_payment_method.m_balance_type_id;
        long balance_source_id = v_balance_source_type[rand()%v_balance_source_type.size()].m_balance_source_id;
        long billing_cycle_type_id = v_billing_cycle[rand()%v_billing_cycle.size()].m_billing_cycle_type_id;
        long staff_id = v_staff[rand()%v_staff.size()].m_staff_id;
        long region_id = v_region[rand()%v_region.size()].m_region_id;

        LOG_INFO(m_logId, "Payment_method:"<<payment_method);
        LOG_INFO(m_logId, "Balance_type_id:"<<balance_type_id);
        LOG_INFO(m_logId, "Balance_source_id:"<<balance_source_id);
        LOG_INFO(m_logId, "Billing_cycle_type_id:"<<billing_cycle_type_id);
        LOG_INFO(m_logId, "Staff_id :"<<staff_id);
        LOG_INFO(m_logId, "Region_id:"<<region_id);

        //get serv_identification info
        ServIdentification m_serv_ident;
        m_serv_ident.setConnection(m_db->getConnection());
        ST_SERV_IDENTIFICATION serv_ident_info;
        if(data.nbr != "")
        {
            LOG_INFO(m_logId, "PayFee::doBiz input nbr:"<<data.nbr);
            serv_ident_info = m_serv_ident.getServIdentInfoByNBR(data.nbr);
        }
        else
        {
            LOG_INFO(m_logId, "PayFee::doBiz no input nbr, system will select a random nbr to do payment.");
            serv_ident_info = m_serv_ident.getRandomServIdentInfo();
            LOG_INFO(m_logId, "PayFee::doBiz the random nbr:"<<serv_ident_info.m_acc_nbr);
        }

        long serv_id = m_serv_ident.serv_identification.m_serv_id;

        LOG_INFO(m_logId, "PayFee::doBiz get serv_acct info");
        ServAcct m_serv_acct;
        m_serv_acct.setConnection(m_db->getConnection());
        ST_SERV_ACCT serv_acct_data = m_serv_acct.getServAcctByServId(serv_id);
        long acct_id = serv_acct_data.m_acct_id;

        LOG_INFO(m_logId, "PayFee::doBiz insert to payment table");
        Payment m_payment;
        m_payment.setConnection(m_db->getConnection());
        long payment_id = m_seq.getScardvcsn();
        m_payment.payment.m_payment_id = payment_id;
        m_payment.payment.m_payment_method = payment_method;
        m_payment.payment.m_party_role_id = 0;
        m_payment.payment.m_payed_method = payment_method;
        m_payment.payment.m_operation_type = "5KA";
        m_payment.payment.m_op_code = "5KA";
        m_payment.payment.m_operated_payment_serial_nbr = payment_id;
        m_payment.payment.m_amount = (int)(100*data.fee);
        m_payment.payment.m_state = "5JA";
        m_payment.payment.m_invoice_id = 0;
        m_payment.payment.m_acct_id = acct_id;
        m_payment.payment.m_staff_org_id = region_id;
        m_payment.payment.m_nbr_org_id = region_id;
        m_payment.payment.m_serv_id = serv_id;
        m_payment.insertData();

        LOG_INFO(m_logId, "PayFee::doBiz insert to acct_balance table");
        AcctBalance m_acct_balance;
        m_acct_balance.setConnection(m_db->getConnection());
        long acct_balance_id=m_seq.getAcctBalanceId();
        m_acct_balance.acct_balance.m_acct_balance_id=acct_balance_id;
        m_acct_balance.acct_balance.m_acct_id=acct_id;
        m_acct_balance.acct_balance.m_balance_type_id=balance_type_id;
        m_acct_balance.acct_balance.m_balance=(int)(100*data.fee);
        m_acct_balance.acct_balance.m_reserve_balance=0;
        m_acct_balance.acct_balance.m_cycle_upper=9999999;
        m_acct_balance.acct_balance.m_cycle_lower=0;
        m_acct_balance.acct_balance.m_cycle_upper_type="5LC";
        m_acct_balance.acct_balance.m_cycle_lower_type="5LC";
        m_acct_balance.acct_balance.m_bill_month_flag="Y";
        m_acct_balance.acct_balance.m_state="00A";
        m_acct_balance.insertData();
        
        LOG_INFO(m_logId, "PayFee::doBiz insert to balance_source table");
        BalanceSource m_balance_source;
        m_balance_source.setConnection(m_db->getConnection());
        m_balance_source.balance_source.m_oper_income_id=m_seq.getBalanceSourceId();
        m_balance_source.balance_source.m_payment_id=payment_id;
        m_balance_source.balance_source.m_acct_balance_id=acct_balance_id;
        m_balance_source.balance_source.m_oper_type="5UA";
        m_balance_source.balance_source.m_staff_id=staff_id;
        m_balance_source.balance_source.m_amount=(int)(100*data.fee);
        m_balance_source.balance_source.m_cur_amount=(int)(100*data.fee);
        m_balance_source.balance_source.m_balance_relation_id=0;
        m_balance_source.balance_source.m_balance_source_id=balance_source_id;
        m_balance_source.balance_source.m_allow_draw="Y";
        m_balance_source.balance_source.m_inv_offer="N";
        m_balance_source.balance_source.m_cur_status="5TA";
        m_balance_source.balance_source.m_state="00A";
        m_balance_source.insertData();

        LOG_INFO(m_logId, "PayFee::doBiz insert to bill_interface table");
        BillInterface m_bill_interface;
        m_bill_interface.setConnection(m_db->getConnection());
        m_bill_interface.bill_interface.m_payment_id=payment_id;
        m_bill_interface.bill_interface.m_acct_id=acct_id;
        m_bill_interface.bill_interface.m_serv_id=serv_id;
        m_bill_interface.bill_interface.m_op_code="JF";
        m_bill_interface.bill_interface.m_staff_id=staff_id;
        m_bill_interface.bill_interface.m_payment_method=payment_method;
        m_bill_interface.bill_interface.m_online_flag=1;
        m_bill_interface.bill_interface.m_state="00A";
        m_bill_interface.bill_interface.m_op_note="缴费";
        m_bill_interface.bill_interface.m_bill_beg_ym=0;
        m_bill_interface.bill_interface.m_bill_end_ym=0;
        m_bill_interface.bill_interface.m_bill_month_flag="Y";
        m_bill_interface.bill_interface.m_serv_pay_flag=0;
        m_bill_interface.insertData();

        LOG_INFO(m_logId, "PayFee::doBiz insert to staff_opr table");
        StaffOpr m_staff_opr;
        m_staff_opr.setConnection(m_db->getConnection());
        m_staff_opr.staff_opr.m_login_accept = m_seq.getScardvcsn();
        m_staff_opr.staff_opr.m_op_code = "JF";
        m_staff_opr.staff_opr.m_payment_method = payment_method;
        m_staff_opr.staff_opr.m_pay_money = (int)(100*data.fee);
        m_staff_opr.staff_opr.m_band_id = 111;
        m_staff_opr.staff_opr.m_serv_id = serv_id;
        m_staff_opr.staff_opr.m_acc_nbr = serv_ident_info.m_acc_nbr;
        m_staff_opr.staff_opr.m_op_note = "缴费";
        m_staff_opr.staff_opr.m_ip_addr = "127.0.0.1";
        m_staff_opr.staff_opr.m_staff_org_id = region_id;
        m_staff_opr.staff_opr.m_nbr_org_id = region_id;
        m_staff_opr.staff_opr.m_staff_id = staff_id;
        m_staff_opr.insertData();

        m_db->commit();
        LOG_DEBUG(m_logId, "PayFee::doBiz end");
    }
    catch(...)
    {
        LOG_ERROR(m_logId, "PayFee::doBiz error");
        m_db->rollback();
    }
}


