#include "DetailItem.hh"
#include "libconfparser/confparser.hpp"
#include "ServIdentification.hh"
#include "Dual.hh"
#include "DetailItemVoice.hh"

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

    LOG_DEBUG(m_logId, "DetailItem::DetailItem end");
}

DetailItem::~DetailItem()
{
    LOG_DEBUG(m_logId, "DetailItem::~DetailItem start");
    m_db->disConnectFromDB();
    LOG_DEBUG(m_logId, "DetailItem::~DetailItem end");
}

void DetailItem::doBiz()
{
    LOG_DEBUG(m_logId, "DetailItem::doBiz start");

    try
    {
        //get serv_identification info
        ServIdentification m_serv_ident;
        m_serv_ident.setConnection(m_db->getConnection());
        ST_SERV_IDENTIFICATION serv_ident_info;
        serv_ident_info = m_serv_ident.getRandomServIdentInfo();
        string msisdn=serv_ident_info.m_acc_nbr;
        serv_ident_info = m_serv_ident.getRandomServIdentInfo();
        string other_party=serv_ident_info.m_acc_nbr;
        LOG_INFO(m_logId, "DetailItem::doBiz the random nbr:"<<serv_ident_info.m_acc_nbr);

        LOG_DEBUG(m_logId, "DetailItem::doBiz insert to detail_item_voice table.");
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
        m_detail_item_voice.detail_item_voice.m_deal_time="1";
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
        LOG_DEBUG(m_logId, "DetailItem::doBiz end");
    }
    catch(...)
    {
        LOG_ERROR(m_logId, "DetailItem::doBiz error");
        m_db->rollback();
    }

}


