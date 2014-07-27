#include "DetailItem.hh"
#include "libconfparser/confparser.hpp"
#include "ServIdentification.hh"
#include "Dual.hh"
#include "DetailItemVoice.hh"
#include "DetailItemMsg.hh"
#include "DetailItemCmsg.hh"
#include "DetailItemCring.hh"

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
        string msisdn=fetch_nbr->doBiz();
        string other_party=fetch_nbr->doBiz();
        LOG_INFO(m_logId, "DetailItem::doVoiceBiz the random nbr:"<<msisdn);

        LOG_DEBUG(m_logId, "DetailItem::doVoiceBiz insert to detail_item_voice table.");
        DetailItemVoice m_detail_item_voice;
        m_detail_item_voice.setConnection(m_db->getConnection());
        m_detail_item_voice.detail_item_voice.m_system_type="vc";
        m_detail_item_voice.detail_item_voice.m_record_type="00";
        m_detail_item_voice.detail_item_voice.m_call_type="00";
        m_detail_item_voice.detail_item_voice.m_imsi="111111111111";
        m_detail_item_voice.detail_item_voice.m_imei="222222222222";
        m_detail_item_voice.detail_item_voice.m_msisdn=msisdn;
        m_detail_item_voice.detail_item_voice.m_other_party=other_party;
        m_detail_item_voice.detail_item_voice.m_call_duration=100;
        m_detail_item_voice.detail_item_voice.m_msc="3333333";
        m_detail_item_voice.detail_item_voice.m_msrn="444444";
        m_detail_item_voice.detail_item_voice.m_lac="12345";
        m_detail_item_voice.detail_item_voice.m_cell_id="12345";
        m_detail_item_voice.detail_item_voice.m_other_lac="34567";
        m_detail_item_voice.detail_item_voice.m_other_cell_id="34567";
        m_detail_item_voice.detail_item_voice.m_trunk_groupout="987654";
        m_detail_item_voice.detail_item_voice.m_trunk_groupin="987654";
        m_detail_item_voice.detail_item_voice.m_service_type="AAA";
        m_detail_item_voice.detail_item_voice.m_service_code="BBB";
        m_detail_item_voice.detail_item_voice.m_hot_flag="0";
        m_detail_item_voice.detail_item_voice.m_status="0";
        m_detail_item_voice.detail_item_voice.m_service_attr="00";
        m_detail_item_voice.detail_item_voice.m_info_num="00";
        m_detail_item_voice.detail_item_voice.m_calling_group_num="9763445";
        m_detail_item_voice.detail_item_voice.m_calling_short_num="9763445";
        m_detail_item_voice.detail_item_voice.m_called_group_num="9763445";
        m_detail_item_voice.detail_item_voice.m_called_short_num="9763445";
        m_detail_item_voice.detail_item_voice.m_block_flag="0";
        m_detail_item_voice.detail_item_voice.m_call_flag="0";
        m_detail_item_voice.detail_item_voice.m_home_area_code="0371";
        m_detail_item_voice.detail_item_voice.m_visit_area_code="0379";
        m_detail_item_voice.detail_item_voice.m_other_home_code="0379";
        m_detail_item_voice.detail_item_voice.m_other_visit_code="0379";
        m_detail_item_voice.detail_item_voice.m_called_code="0371";
        m_detail_item_voice.detail_item_voice.m_user_type="0";
        m_detail_item_voice.detail_item_voice.m_roam_type="0";
        m_detail_item_voice.detail_item_voice.m_fee_type="0";
        m_detail_item_voice.detail_item_voice.m_dial_type="000";
        m_detail_item_voice.detail_item_voice.m_chat_type="000";
        m_detail_item_voice.detail_item_voice.m_fee1=100;
        m_detail_item_voice.detail_item_voice.m_fee2=0;
        m_detail_item_voice.detail_item_voice.m_fee3=0;
        m_detail_item_voice.detail_item_voice.m_old_fee1=0;
        m_detail_item_voice.detail_item_voice.m_old_fee2=0;
        m_detail_item_voice.detail_item_voice.m_old_fee3=0;
        m_detail_item_voice.detail_item_voice.m_info_fee1="0";
        m_detail_item_voice.detail_item_voice.m_info_fee2="0";
        m_detail_item_voice.detail_item_voice.m_info_fee3="0";
        m_detail_item_voice.detail_item_voice.m_file_name="fee.txt";
        m_detail_item_voice.detail_item_voice.m_group_id="12345";
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

        m_db->commit();
        LOG_DEBUG(m_logId, "DetailItem::doVoiceBiz end");
    }
    catch(...)
    {
        LOG_ERROR(m_logId, "DetailItem::doVoiceBiz error");
        m_db->rollback();
    }

}

void DetailItem::doMsgBiz()
{
    LOG_DEBUG(m_logId, "DetailItem::doMsgBiz start");

    try
    {
        string msisdn=fetch_nbr->doBiz();
        string other_party=fetch_nbr->doBiz();
        LOG_INFO(m_logId, "DetailItem::doMsgBiz the random nbr:"<<msisdn);

        LOG_DEBUG(m_logId, "DetailItem::doMsgBiz insert to detail_item_voice table.");
        DetailItemMsg m_detail_item_msg;
        m_detail_item_msg.setConnection(m_db->getConnection());

        m_detail_item_msg.detail_item_msg.m_system_type="sg";
        m_detail_item_msg.detail_item_msg.m_ism_type="01";
        m_detail_item_msg.detail_item_msg.m_sm_type="11";
        m_detail_item_msg.detail_item_msg.m_msg_id="1208439483207035";
        m_detail_item_msg.detail_item_msg.m_imsi="222222222";
        m_detail_item_msg.detail_item_msg.m_imei="33333333";
        m_detail_item_msg.detail_item_msg.m_msisdn=msisdn;
        m_detail_item_msg.detail_item_msg.m_other_party=other_party;
        m_detail_item_msg.detail_item_msg.m_msg_length=74;
        m_detail_item_msg.detail_item_msg.m_status="0";
        m_detail_item_msg.detail_item_msg.m_priority="0";
        m_detail_item_msg.detail_item_msg.m_gateway_code="A01";
        m_detail_item_msg.detail_item_msg.m_f_gateway_code="B01";
        m_detail_item_msg.detail_item_msg.m_serv_code="000";
        m_detail_item_msg.detail_item_msg.m_sm_center_code="8601234";
        m_detail_item_msg.detail_item_msg.m_billing_flag="01";
        m_detail_item_msg.detail_item_msg.m_service_attr="V03";
        m_detail_item_msg.detail_item_msg.m_home_area_code="+86";
        m_detail_item_msg.detail_item_msg.m_user_type="1";
        m_detail_item_msg.detail_item_msg.m_fee1=10;
        m_detail_item_msg.detail_item_msg.m_old_fee1=0;
        m_detail_item_msg.detail_item_msg.m_info_fee1="0";
        m_detail_item_msg.detail_item_msg.m_file_name="dealmsgfile.txt";
        m_detail_item_msg.detail_item_msg.m_group_id="C01";
        m_detail_item_msg.detail_item_msg.m_product_code="P01";
        m_detail_item_msg.detail_item_msg.m_chat_type="0";
        m_detail_item_msg.detail_item_msg.m_brand_code="A";
        m_detail_item_msg.detail_item_msg.m_dealfile="0";

        m_detail_item_msg.insertData();

        m_db->commit();
        LOG_DEBUG(m_logId, "DetailItem::doMsgBiz end");
    }
    catch(...)
    {
        LOG_ERROR(m_logId, "DetailItem::doMsgBiz error");
        m_db->rollback();
    }

}

void DetailItem::doCmsgBiz()
{
    LOG_DEBUG(m_logId, "DetailItem::doCmsgBiz start");

    try
    {
        string msisdn=fetch_nbr->doBiz();
        string other_party=fetch_nbr->doBiz();
        LOG_INFO(m_logId, "DetailItem::doCmsgBiz the random nbr:"<<msisdn);

        LOG_DEBUG(m_logId, "DetailItem::doCmsgBiz insert to detail_item_voice table.");
        DetailItemCmsg m_detail_item_cmsg;
        m_detail_item_cmsg.setConnection(m_db->getConnection());

        m_detail_item_cmsg.detail_item_cmsg.m_system_type="mm";
        m_detail_item_cmsg.detail_item_cmsg.m_sm_type="01";
        m_detail_item_cmsg.detail_item_cmsg.m_record_type="0";
        m_detail_item_cmsg.detail_item_cmsg.m_service_type="01";
        m_detail_item_cmsg.detail_item_cmsg.m_seg_num="123";
        m_detail_item_cmsg.detail_item_cmsg.m_imsi="34343924830";
        m_detail_item_cmsg.detail_item_cmsg.m_imei="48302850432";
        m_detail_item_cmsg.detail_item_cmsg.m_msisdn=msisdn;
        m_detail_item_cmsg.detail_item_cmsg.m_other_party=other_party;
        m_detail_item_cmsg.detail_item_cmsg.m_call_duration=200;
        m_detail_item_cmsg.detail_item_cmsg.m_times=2;
        m_detail_item_cmsg.detail_item_cmsg.m_down_flow=10;
        m_detail_item_cmsg.detail_item_cmsg.m_up_flow=20;
        m_detail_item_cmsg.detail_item_cmsg.m_total_flow=30;
        m_detail_item_cmsg.detail_item_cmsg.m_nai="CARD";
        m_detail_item_cmsg.detail_item_cmsg.m_ip_address="127.0.0.1";
        m_detail_item_cmsg.detail_item_cmsg.m_sp_code="china";
        m_detail_item_cmsg.detail_item_cmsg.m_serv_code="0001999999";
        m_detail_item_cmsg.detail_item_cmsg.m_oper_code="12";
        m_detail_item_cmsg.detail_item_cmsg.m_billing_type="00";
        m_detail_item_cmsg.detail_item_cmsg.m_rate_unit="00";
        m_detail_item_cmsg.detail_item_cmsg.m_status="0";
        m_detail_item_cmsg.detail_item_cmsg.m_sys_id="24353";
        m_detail_item_cmsg.detail_item_cmsg.m_sys_intra_key="23320140727213200";
        m_detail_item_cmsg.detail_item_cmsg.m_service_attr="5";
        m_detail_item_cmsg.detail_item_cmsg.m_home_area_code="86";
        m_detail_item_cmsg.detail_item_cmsg.m_chat_type="11";
        m_detail_item_cmsg.detail_item_cmsg.m_user_type="3";
        m_detail_item_cmsg.detail_item_cmsg.m_fee1=50;
        m_detail_item_cmsg.detail_item_cmsg.m_fee2=0;
        m_detail_item_cmsg.detail_item_cmsg.m_old_fee1=50;
        m_detail_item_cmsg.detail_item_cmsg.m_old_fee2=0;
        m_detail_item_cmsg.detail_item_cmsg.m_info_fee1="0";
        m_detail_item_cmsg.detail_item_cmsg.m_info_fee2="0";
        m_detail_item_cmsg.detail_item_cmsg.m_file_name="dealcmsgfile.txt";
        m_detail_item_cmsg.detail_item_cmsg.m_group_id="G";
        m_detail_item_cmsg.detail_item_cmsg.m_product_code="P";
        m_detail_item_cmsg.detail_item_cmsg.m_brand_code="A";
        m_detail_item_cmsg.detail_item_cmsg.m_dealfile="0";

        m_detail_item_cmsg.insertData();

        m_db->commit();
        LOG_DEBUG(m_logId, "DetailItem::doCmsgBiz end");
    }
    catch(...)
    {
        LOG_ERROR(m_logId, "DetailItem::doCmsgBiz error");
        m_db->rollback();
    }

}

void DetailItem::doCringBiz()
{
    LOG_DEBUG(m_logId, "DetailItem::doCringBiz start");

    try
    {
        string msisdn=fetch_nbr->doBiz();
        string other_party=fetch_nbr->doBiz();
        LOG_INFO(m_logId, "DetailItem::doCringBiz the random nbr:"<<msisdn);

        LOG_DEBUG(m_logId, "DetailItem::doCringBiz insert to detail_item_voice table.");
        DetailItemCring m_detail_item_cring;
        m_detail_item_cring.setConnection(m_db->getConnection());

        m_detail_item_cring.detail_item_cring.m_system_type="bj";
        m_detail_item_cring.detail_item_cring.m_record_type="03";
        m_detail_item_cring.detail_item_cring.m_call_type="01";
        m_detail_item_cring.detail_item_cring.m_msisdn=msisdn;
        m_detail_item_cring.detail_item_cring.m_other_party=other_party;
        m_detail_item_cring.detail_item_cring.m_call_duration="10";
        m_detail_item_cring.detail_item_cring.m_record_gen_type="1";
        m_detail_item_cring.detail_item_cring.m_service_key="c";
        m_detail_item_cring.detail_item_cring.m_service_id="d3489304";
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
        m_detail_item_cring.detail_item_cring.m_fee1="300";
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

        m_db->commit();
        LOG_DEBUG(m_logId, "DetailItem::doCringBiz end");
    }
    catch(...)
    {
        LOG_ERROR(m_logId, "DetailItem::doCringBiz error");
        m_db->rollback();
    }

}

