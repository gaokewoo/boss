#include "DetailItem.hh"
#include "libconfparser/confparser.hpp"
#include "ServIdentification.hh"
#include "Dual.hh"
#include "DetailItemVoice.hh"
#include "DetailItemMsg.hh"
#include "DetailItemCmsg.hh"
#include "DetailItemCring.hh"
#include "ServAcct.hh"
#include "Acct.hh"
#include "AcctItemSource.hh"
#include "AcctItem.hh"
#include "DetailItemConst.hh"

using namespace DetailItemNameSpace;

FetchNbr * DetailItem::fetch_nbr = NULL;
DetailItem::DetailItem(LoggerId logId)
{
    m_logId = logId;
    LOG_DEBUG(m_logId, "DetailItem::DetailItem start");

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

    m_seq.setConnection(m_db->getConnection());

    if(fetch_nbr==NULL)
      fetch_nbr = new FetchNbr(logId);

    LOG_DEBUG(m_logId, "DetailItem::DetailItem end");
}

DetailItem::~DetailItem()
{
    LOG_DEBUG(m_logId, "DetailItem::~DetailItem start");
    if(fetch_nbr != NULL)
    {
        delete fetch_nbr;
        fetch_nbr = NULL;
    }
    m_db->disConnectFromDB();
    LOG_DEBUG(m_logId, "DetailItem::~DetailItem end");
}

void DetailItem::doBiz(int type)
{
    
    if(0==type)
    {
        doVoiceBiz();
    }
    else if(1==type)
    {
        doMsgBiz();
    }
    else if(2==type)
    {
        doCmsgBiz();
    }
    else if(3==type)
    {
        doCringBiz();
    }
    else
    {
        LOG_ERROR(m_logId, "DetailItem::doBiz error--not support type:"<<type);
    }
   
}


void DetailItem::doVoiceBiz()
{
    LOG_DEBUG(m_logId, "DetailItem::doVoiceBiz start");

    try
    {
        using namespace Voice;

        string msisdn=fetch_nbr->doBiz();
        string other_party=fetch_nbr->doBiz();
        LOG_INFO(m_logId, "DetailItem::doVoiceBiz the random nbr:"<<msisdn);

        LOG_DEBUG(m_logId, "DetailItem::doVoiceBiz insert to detail_item_voice table.");
        DetailItemVoice m_detail_item_voice;
        m_detail_item_voice.setConnection(m_db->getConnection());
        m_detail_item_voice.detail_item_voice.m_system_type=R(a);
        m_detail_item_voice.detail_item_voice.m_record_type=R(b);
        m_detail_item_voice.detail_item_voice.m_call_type=R(c);
        m_detail_item_voice.detail_item_voice.m_imsi=R(A);
        m_detail_item_voice.detail_item_voice.m_imei=R(A);
        m_detail_item_voice.detail_item_voice.m_msisdn=msisdn;
        m_detail_item_voice.detail_item_voice.m_other_party=other_party;
        m_detail_item_voice.detail_item_voice.m_call_duration=R(B);
        m_detail_item_voice.detail_item_voice.m_msc=R(A);
        m_detail_item_voice.detail_item_voice.m_msrn=R(A);
        m_detail_item_voice.detail_item_voice.m_lac=R(A);
        m_detail_item_voice.detail_item_voice.m_cell_id=R(A);
        m_detail_item_voice.detail_item_voice.m_other_lac=R(A);
        m_detail_item_voice.detail_item_voice.m_other_cell_id=R(A);
        m_detail_item_voice.detail_item_voice.m_trunk_groupout=R(A);
        m_detail_item_voice.detail_item_voice.m_trunk_groupin=R(A);
        m_detail_item_voice.detail_item_voice.m_service_type="AAA";
        m_detail_item_voice.detail_item_voice.m_service_code="BBB";
        m_detail_item_voice.detail_item_voice.m_hot_flag="0";
        m_detail_item_voice.detail_item_voice.m_status="0";
        m_detail_item_voice.detail_item_voice.m_service_attr="00";
        m_detail_item_voice.detail_item_voice.m_info_num="00";
        m_detail_item_voice.detail_item_voice.m_calling_group_num=R(A);
        m_detail_item_voice.detail_item_voice.m_calling_short_num=R(A);
        m_detail_item_voice.detail_item_voice.m_called_group_num=R(A);
        m_detail_item_voice.detail_item_voice.m_called_short_num=R(A);
        m_detail_item_voice.detail_item_voice.m_block_flag="0";
        m_detail_item_voice.detail_item_voice.m_call_flag="0";
        m_detail_item_voice.detail_item_voice.m_home_area_code=generator.getRandomInfo().region_nbr;
        m_detail_item_voice.detail_item_voice.m_visit_area_code=generator.getRandomInfo().region_nbr;
        m_detail_item_voice.detail_item_voice.m_other_home_code=generator.getRandomInfo().region_nbr;
        m_detail_item_voice.detail_item_voice.m_other_visit_code=generator.getRandomInfo().region_nbr;
        m_detail_item_voice.detail_item_voice.m_called_code=generator.getRandomInfo().region_nbr;
        m_detail_item_voice.detail_item_voice.m_user_type="0";
        m_detail_item_voice.detail_item_voice.m_roam_type="0";
        m_detail_item_voice.detail_item_voice.m_fee_type="0";
        m_detail_item_voice.detail_item_voice.m_dial_type="000";
        m_detail_item_voice.detail_item_voice.m_chat_type="000";
        int fee=R(B);
        m_detail_item_voice.detail_item_voice.m_fee1=fee;
        m_detail_item_voice.detail_item_voice.m_fee2=0;
        m_detail_item_voice.detail_item_voice.m_fee3=0;
        m_detail_item_voice.detail_item_voice.m_old_fee1=0;
        m_detail_item_voice.detail_item_voice.m_old_fee2=0;
        m_detail_item_voice.detail_item_voice.m_old_fee3=0;
        m_detail_item_voice.detail_item_voice.m_info_fee1="0";
        m_detail_item_voice.detail_item_voice.m_info_fee2="0";
        m_detail_item_voice.detail_item_voice.m_info_fee3="0";
        m_detail_item_voice.detail_item_voice.m_file_name="fee.txt";
        m_detail_item_voice.detail_item_voice.m_group_id=R(A);
        m_detail_item_voice.detail_item_voice.m_product_code="0";
        m_detail_item_voice.detail_item_voice.m_a_number="0";
        m_detail_item_voice.detail_item_voice.m_brand_code="0";
        m_detail_item_voice.detail_item_voice.m_roam_type_query="0";
        m_detail_item_voice.detail_item_voice.m_fee_type_query="0";
        m_detail_item_voice.detail_item_voice.m_dealfile="dealfile.txt";
        m_detail_item_voice.detail_item_voice.m_error_code="0";
        m_detail_item_voice.detail_item_voice.m_favour_fee1="0";
        m_detail_item_voice.detail_item_voice.m_favour_fee2="0";
        m_detail_item_voice.detail_item_voice.m_favour_fee3="0";
        m_detail_item_voice.detail_item_voice.m_favour_flag="0";
        m_detail_item_voice.insertData();

        doInsAcct(msisdn,1001,fee);

        m_db->commit();
        LOG_DEBUG(m_logId, "DetailItem::doVoiceBiz end");
    }
    catch(...)
    {
        LOG_ERROR(m_logId, "DetailItem::doVoiceBiz error");
        m_db->rollback();
        exit(-1);
    }

}

void DetailItem::doMsgBiz()
{
    LOG_DEBUG(m_logId, "DetailItem::doMsgBiz start");

    static long long msgid=10000000000;
    msgid++;
    char s_msgid[13];
    snprintf(s_msgid,12,"%lld",msgid);
    try
    {
        using namespace Msg;

        string msisdn=fetch_nbr->doBiz();
        string other_party=fetch_nbr->doBiz();
        LOG_INFO(m_logId, "DetailItem::doMsgBiz the random nbr:"<<msisdn);

        LOG_DEBUG(m_logId, "DetailItem::doMsgBiz insert to detail_item_voice table.");
        DetailItemMsg m_detail_item_msg;
        m_detail_item_msg.setConnection(m_db->getConnection());

        m_detail_item_msg.detail_item_msg.m_system_type="sg";
        m_detail_item_msg.detail_item_msg.m_ism_type=R(a);
        m_detail_item_msg.detail_item_msg.m_sm_type=R(b);
        m_detail_item_msg.detail_item_msg.m_msg_id=s_msgid;
        m_detail_item_msg.detail_item_msg.m_imsi=R(A);
        m_detail_item_msg.detail_item_msg.m_imei=R(A);
        m_detail_item_msg.detail_item_msg.m_msisdn=msisdn;
        m_detail_item_msg.detail_item_msg.m_other_party=other_party;
        m_detail_item_msg.detail_item_msg.m_msg_length=74;
        m_detail_item_msg.detail_item_msg.m_status="0";
        m_detail_item_msg.detail_item_msg.m_priority="0";
        m_detail_item_msg.detail_item_msg.m_gateway_code="A01";
        m_detail_item_msg.detail_item_msg.m_f_gateway_code="B01";
        m_detail_item_msg.detail_item_msg.m_serv_code="000";
        m_detail_item_msg.detail_item_msg.m_sm_center_code="86"+R(A);
        m_detail_item_msg.detail_item_msg.m_billing_flag="01";
        m_detail_item_msg.detail_item_msg.m_service_attr="V03";
        m_detail_item_msg.detail_item_msg.m_home_area_code="+86";
        m_detail_item_msg.detail_item_msg.m_user_type="1";
        int fee=R(B);
        m_detail_item_msg.detail_item_msg.m_fee1=fee;
        m_detail_item_msg.detail_item_msg.m_old_fee1=0;
        m_detail_item_msg.detail_item_msg.m_info_fee1="0";
        m_detail_item_msg.detail_item_msg.m_file_name="dealmsgfile.txt";
        m_detail_item_msg.detail_item_msg.m_group_id="C01";
        m_detail_item_msg.detail_item_msg.m_product_code="P01";
        m_detail_item_msg.detail_item_msg.m_chat_type="0";
        m_detail_item_msg.detail_item_msg.m_brand_code="A";
        m_detail_item_msg.detail_item_msg.m_dealfile="0";

        m_detail_item_msg.insertData();

        doInsAcct(msisdn,1002,fee);

        m_db->commit();
        LOG_DEBUG(m_logId, "DetailItem::doMsgBiz end");
    }
    catch(...)
    {
        LOG_ERROR(m_logId, "DetailItem::doMsgBiz error");
        m_db->rollback();
        exit(-1);
    }

}

void DetailItem::doCmsgBiz()
{
    LOG_DEBUG(m_logId, "DetailItem::doCmsgBiz start");

    try
    {
        using namespace Cmsg;

        string msisdn=fetch_nbr->doBiz();
        string other_party=fetch_nbr->doBiz();
        LOG_INFO(m_logId, "DetailItem::doCmsgBiz the random nbr:"<<msisdn);

        LOG_DEBUG(m_logId, "DetailItem::doCmsgBiz insert to detail_item_voice table.");
        DetailItemCmsg m_detail_item_cmsg;
        m_detail_item_cmsg.setConnection(m_db->getConnection());

        m_detail_item_cmsg.detail_item_cmsg.m_system_type="mm";
        m_detail_item_cmsg.detail_item_cmsg.m_sm_type=R(a);
        m_detail_item_cmsg.detail_item_cmsg.m_record_type=R(b);
        m_detail_item_cmsg.detail_item_cmsg.m_service_type=R(c);
        m_detail_item_cmsg.detail_item_cmsg.m_seg_num=R(A);
        m_detail_item_cmsg.detail_item_cmsg.m_imsi=R(A);
        m_detail_item_cmsg.detail_item_cmsg.m_imei=R(A);
        m_detail_item_cmsg.detail_item_cmsg.m_msisdn=msisdn;
        m_detail_item_cmsg.detail_item_cmsg.m_other_party=other_party;
        m_detail_item_cmsg.detail_item_cmsg.m_call_duration=R(B);
        m_detail_item_cmsg.detail_item_cmsg.m_times=2;
        m_detail_item_cmsg.detail_item_cmsg.m_down_flow=10;
        m_detail_item_cmsg.detail_item_cmsg.m_up_flow=20;
        m_detail_item_cmsg.detail_item_cmsg.m_total_flow=30;
        m_detail_item_cmsg.detail_item_cmsg.m_nai="CARD";
        m_detail_item_cmsg.detail_item_cmsg.m_ip_address="127.0.0.1";
        m_detail_item_cmsg.detail_item_cmsg.m_sp_code="china";
        m_detail_item_cmsg.detail_item_cmsg.m_serv_code=R(A);
        m_detail_item_cmsg.detail_item_cmsg.m_oper_code="12";
        m_detail_item_cmsg.detail_item_cmsg.m_billing_type="00";
        m_detail_item_cmsg.detail_item_cmsg.m_rate_unit="00";
        m_detail_item_cmsg.detail_item_cmsg.m_status="0";
        m_detail_item_cmsg.detail_item_cmsg.m_sys_id=R(A);
        m_detail_item_cmsg.detail_item_cmsg.m_sys_intra_key=R(A);
        m_detail_item_cmsg.detail_item_cmsg.m_service_attr="5";
        m_detail_item_cmsg.detail_item_cmsg.m_home_area_code="86";
        m_detail_item_cmsg.detail_item_cmsg.m_chat_type="11";
        m_detail_item_cmsg.detail_item_cmsg.m_user_type="3";
        int fee=R(B);
        m_detail_item_cmsg.detail_item_cmsg.m_fee1=fee;
        m_detail_item_cmsg.detail_item_cmsg.m_fee2=0;
        m_detail_item_cmsg.detail_item_cmsg.m_old_fee1=fee;
        m_detail_item_cmsg.detail_item_cmsg.m_old_fee2=0;
        m_detail_item_cmsg.detail_item_cmsg.m_info_fee1="0";
        m_detail_item_cmsg.detail_item_cmsg.m_info_fee2="0";
        m_detail_item_cmsg.detail_item_cmsg.m_file_name="dealcmsgfile.txt";
        m_detail_item_cmsg.detail_item_cmsg.m_group_id="G";
        m_detail_item_cmsg.detail_item_cmsg.m_product_code="P";
        m_detail_item_cmsg.detail_item_cmsg.m_brand_code="A";
        m_detail_item_cmsg.detail_item_cmsg.m_dealfile="0";

        m_detail_item_cmsg.insertData();

        doInsAcct(msisdn,1003,fee);

        m_db->commit();
        LOG_DEBUG(m_logId, "DetailItem::doCmsgBiz end");
    }
    catch(...)
    {
        LOG_ERROR(m_logId, "DetailItem::doCmsgBiz error");
        m_db->rollback();
        exit(-1);
    }

}

void DetailItem::doCringBiz()
{
    LOG_DEBUG(m_logId, "DetailItem::doCringBiz start");

    try
    {
        using namespace Cring;

        string msisdn=fetch_nbr->doBiz();
        string other_party=fetch_nbr->doBiz();
        LOG_INFO(m_logId, "DetailItem::doCringBiz the random nbr:"<<msisdn);

        LOG_DEBUG(m_logId, "DetailItem::doCringBiz insert to detail_item_voice table.");
        DetailItemCring m_detail_item_cring;
        m_detail_item_cring.setConnection(m_db->getConnection());

        m_detail_item_cring.detail_item_cring.m_system_type="bj";
        m_detail_item_cring.detail_item_cring.m_record_type=R(a);
        m_detail_item_cring.detail_item_cring.m_call_type="01";
        m_detail_item_cring.detail_item_cring.m_msisdn=msisdn;
        m_detail_item_cring.detail_item_cring.m_other_party=other_party;
        char tmp[6];
        snprintf(tmp,6,"%d",R(B));
        m_detail_item_cring.detail_item_cring.m_call_duration=tmp;
        m_detail_item_cring.detail_item_cring.m_record_gen_type="1";
        m_detail_item_cring.detail_item_cring.m_service_key="c";
        m_detail_item_cring.detail_item_cring.m_service_id=R(A);
        m_detail_item_cring.detail_item_cring.m_sp_code="china";
        m_detail_item_cring.detail_item_cring.m_serv_code="A3";
        m_detail_item_cring.detail_item_cring.m_oper_code="B3";
        m_detail_item_cring.detail_item_cring.m_home_area_code="86";
        m_detail_item_cring.detail_item_cring.m_billing_type="A";
        m_detail_item_cring.detail_item_cring.m_user_level="A";
        m_detail_item_cring.detail_item_cring.m_user_type="C";
        m_detail_item_cring.detail_item_cring.m_brand_code="A";
        m_detail_item_cring.detail_item_cring.m_roam_type="0";
        m_detail_item_cring.detail_item_cring.m_fee_type="0";
        int fee=R(B);
        snprintf(tmp,6,"%d",fee);
        m_detail_item_cring.detail_item_cring.m_fee1=tmp;
        m_detail_item_cring.detail_item_cring.m_fee2="0";
        m_detail_item_cring.detail_item_cring.m_fee3="0";
        m_detail_item_cring.detail_item_cring.m_old_fee1="0";
        m_detail_item_cring.detail_item_cring.m_old_fee2="0";
        m_detail_item_cring.detail_item_cring.m_old_fee3="0";
        m_detail_item_cring.detail_item_cring.m_info_fee1="0";
        m_detail_item_cring.detail_item_cring.m_info_fee2="0";
        m_detail_item_cring.detail_item_cring.m_info_fee3="0";
        m_detail_item_cring.detail_item_cring.m_file_name="dealcringfile.txt";
        m_detail_item_cring.detail_item_cring.m_group_id="G2";
        m_detail_item_cring.detail_item_cring.m_product_code="P2";
        m_detail_item_cring.detail_item_cring.m_dealfile="0";

        m_detail_item_cring.insertData();

        doInsAcct(msisdn,1004,fee);

        m_db->commit();
        LOG_DEBUG(m_logId, "DetailItem::doCringBiz end");
    }
    catch(...)
    {
        LOG_ERROR(m_logId, "DetailItem::doCringBiz error");
        m_db->rollback();
        exit(-1);
    }

}

void DetailItem::doInsAcct(string nbr,int item,int fee)
{
    try
    {
        long l_amount = (long)(fee*0.8);
        long l_should_pay = fee;
        long l_favour_fee = l_should_pay-l_amount;

        ServIdentification m_serv_ident;
        m_serv_ident.setConnection(m_db->getConnection());
        ST_SERV_IDENTIFICATION serv_ident_info;
        serv_ident_info = m_serv_ident.getServIdentInfoByNBR(nbr);

        long serv_id = m_serv_ident.serv_identification.m_serv_id;

        Dual dual;
        dual.setConnection(m_db->getConnection());
        string cym = dual.getSysDateYYYYMM();

        ServAcct m_serv_acct;
        m_serv_acct.setConnection(m_db->getConnection());
        ST_SERV_ACCT serv_acct_data = m_serv_acct.getServAcctByServId(serv_id);
        long acct_id = serv_acct_data.m_acct_id;

        Acct m_acct;
        m_acct.setConnection(m_db->getConnection());
        ST_ACCT acct_data = m_acct.getAcctByAcctId(acct_id);

        long ym = atol(cym.c_str());
        if(ym>acct_data.m_owe_min_ym) ym = acct_data.m_owe_min_ym;
        long owe_fee = acct_data.m_owe_fee+(int)(l_amount);
        m_acct.setAcctOweMinYMAndOweFee(acct_id,ym,owe_fee);

        AcctItemSource m_acct_item_source;
        m_acct_item_source.setConnection(m_db->getConnection());
        long item_source_id=m_seq.getItemSourceId();
        m_acct_item_source.acct_item_source.m_item_source_id=item_source_id;
        m_acct_item_source.acct_item_source.m_acct_item_type_id=item;
        m_acct_item_source.acct_item_source.m_item_source_type="52A";
        m_acct_item_source.acct_item_source.m_name="帐目应收费用";
        m_acct_item_source.acct_item_source.m_comments="新增";
        m_acct_item_source.insertData();

        AcctItem m_acct_item;
        m_acct_item.setConnection(m_db->getConnection());

        ST_ACCT_ITEM acct_item = m_acct_item.getAcctItemByAcctIdServId(acct_id,serv_id,item,"00A");
        if(acct_item.m_acct_item_id != 0)
        {
            long acct_item_id=acct_item.m_acct_item_id;
            long amount=acct_item.m_amount+l_amount;
            long should_pay=acct_item.m_should_pay+l_should_pay;
            long favour_fee=acct_item.m_favour_fee+l_favour_fee;
            m_acct_item.updateOtherFeeInAcctItemByAcctItemId(acct_item_id,amount,should_pay,favour_fee);
        }
        else
        {
            long acct_item_id=m_seq.getAcctItemId();
            m_acct_item.acct_item.m_acct_item_id=acct_item_id;
            m_acct_item.acct_item.m_item_source_id=item_source_id;
            m_acct_item.acct_item.m_bill_id=0;
            m_acct_item.acct_item.m_acct_item_type_id=item;
            m_acct_item.acct_item.m_billing_cycle_id=ym;
            m_acct_item.acct_item.m_acct_id=acct_id;
            m_acct_item.acct_item.m_serv_id=serv_id;
            m_acct_item.acct_item.m_amount=l_amount;
            m_acct_item.acct_item.m_fee_cycle_id=0;
            m_acct_item.acct_item.m_payment_method=0;
            m_acct_item.acct_item.m_state="00A";
            m_acct_item.acct_item.m_latn_id=10017;
            m_acct_item.acct_item.m_ai_total_id=0;
            m_acct_item.acct_item.m_acc_nbr=serv_ident_info.m_acc_nbr;
            m_acct_item.acct_item.m_should_pay=l_should_pay;
            m_acct_item.acct_item.m_favour_fee=l_favour_fee;
            m_acct_item.acct_item.m_times=0;
            m_acct_item.acct_item.m_duration=0;
            m_acct_item.acct_item.m_month_wrtoff_fee=0;
            m_acct_item.acct_item.m_pay_wrtoff_fee=0;
            m_acct_item.acct_item.m_attr_code="";
            m_acct_item.insertData();
        }

        m_db->commit();
    }
    catch(...)
    {
        LOG_ERROR(m_logId, "AdjustAcctItem::doBiz error");
        m_db->rollback();
        exit(-1);
    }
}
