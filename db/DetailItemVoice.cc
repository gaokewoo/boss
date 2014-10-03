#include "DetailItemVoice.hh"
#include "Dual.hh"

void DetailItemVoice::insertData()
{
    type=INSERT;

    Dual dual;
    dual.setConnection(conn);
    string m_ym = dual.getSysDateYYYYMM();

    setSQL("INSERT INTO DETAIL_ITEM_VOICE"+m_ym+"(SYSTEM_TYPE,RECORD_TYPE,CALL_TYPE,IMSI,IMEI,MSISDN,OTHER_PARTY,START_DATETIME,CALL_DURATION,MSC,MSRN,LAC,CELL_ID,OTHER_LAC,OTHER_CELL_ID,TRUNK_GROUPOUT,TRUNK_GROUPIN,SERVICE_TYPE,SERVICE_CODE,HOT_FLAG,STATUS,SERVICE_ATTR,INFO_NUM,CALLING_GROUP_NUM,CALLING_SHORT_NUM,CALLED_GROUP_NUM,CALLED_SHORT_NUM,BLOCK_FLAG,CALL_FLAG,HOME_AREA_CODE,VISIT_AREA_CODE,OTHER_HOME_CODE,OTHER_VISIT_CODE,CALLED_CODE,USER_TYPE,ROAM_TYPE,FEE_TYPE,DIAL_TYPE,CHAT_TYPE,FEE1,FEE2,FEE3,OLD_FEE1,OLD_FEE2,OLD_FEE3,INFO_FEE1,INFO_FEE2,INFO_FEE3,FILE_NAME,DEAL_TIME,GROUP_ID,PRODUCT_CODE,A_NUMBER,BRAND_CODE,ROAM_TYPE_QUERY,FEE_TYPE_QUERY,DEALFILE,ERROR_CODE,FAVOUR_FEE1,FAVOUR_FEE2,FAVOUR_FEE3,FAVOUR_FLAG)VALUES (:SYSTEM_TYPE,:RECORD_TYPE,:CALL_TYPE,:IMSI,:IMEI,:MSISDN,:OTHER_PARTY,SYSDATE,:CALL_DURATION,:MSC,:MSRN,:LAC,:CELL_ID,:OTHER_LAC,:OTHER_CELL_ID,:TRUNK_GROUPOUT,:TRUNK_GROUPIN,:SERVICE_TYPE,:SERVICE_CODE,:HOT_FLAG,:STATUS,:SERVICE_ATTR,:INFO_NUM,:CALLING_GROUP_NUM,:CALLING_SHORT_NUM,:CALLED_GROUP_NUM,:CALLED_SHORT_NUM,:BLOCK_FLAG,:CALL_FLAG,:HOME_AREA_CODE,:VISIT_AREA_CODE,:OTHER_HOME_CODE,:OTHER_VISIT_CODE,:CALLED_CODE,:USER_TYPE,:ROAM_TYPE,:FEE_TYPE,:DIAL_TYPE,:CHAT_TYPE,:FEE1,:FEE2,:FEE3,:OLD_FEE1,:OLD_FEE2,:OLD_FEE3,:INFO_FEE1,:INFO_FEE2,:INFO_FEE3,:FILE_NAME,SYSDATE,:GROUP_ID,:PRODUCT_CODE,:A_NUMBER,:BRAND_CODE,:ROAM_TYPE_QUERY,:FEE_TYPE_QUERY,:DEALFILE,:ERROR_CODE,:FAVOUR_FEE1,:FAVOUR_FEE2,:FAVOUR_FEE3,:FAVOUR_FLAG)");
    executeUpdate();
}

void DetailItemVoice::prepareSQL()
{
    if (type == INSERT)
    {
        stmt->setString(1,detail_item_voice.m_system_type);
        stmt->setString(2,detail_item_voice.m_record_type);
        stmt->setString(3,detail_item_voice.m_call_type);
        stmt->setString(4,detail_item_voice.m_imsi);
        stmt->setString(5,detail_item_voice.m_imei);
        stmt->setString(6,detail_item_voice.m_msisdn);
        stmt->setString(7,detail_item_voice.m_other_party);
        stmt->setNumber(8,detail_item_voice.m_call_duration);
        stmt->setString(9,detail_item_voice.m_msc);
        stmt->setString(10,detail_item_voice.m_msrn);
        stmt->setString(11,detail_item_voice.m_lac);
        stmt->setString(12,detail_item_voice.m_cell_id);
        stmt->setString(13,detail_item_voice.m_other_lac);
        stmt->setString(14,detail_item_voice.m_other_cell_id);
        stmt->setString(15,detail_item_voice.m_trunk_groupout);
        stmt->setString(16,detail_item_voice.m_trunk_groupin);
        stmt->setString(17,detail_item_voice.m_service_type);
        stmt->setString(18,detail_item_voice.m_service_code);
        stmt->setString(19,detail_item_voice.m_hot_flag);
        stmt->setString(20,detail_item_voice.m_status);
        stmt->setString(21,detail_item_voice.m_service_attr);
        stmt->setString(22,detail_item_voice.m_info_num);
        stmt->setString(23,detail_item_voice.m_calling_group_num);
        stmt->setString(24,detail_item_voice.m_calling_short_num);
        stmt->setString(25,detail_item_voice.m_called_group_num);
        stmt->setString(26,detail_item_voice.m_called_short_num);
        stmt->setString(27,detail_item_voice.m_block_flag);
        stmt->setString(28,detail_item_voice.m_call_flag);
        stmt->setString(29,detail_item_voice.m_home_area_code);
        stmt->setString(30,detail_item_voice.m_visit_area_code);
        stmt->setString(31,detail_item_voice.m_other_home_code);
        stmt->setString(32,detail_item_voice.m_other_visit_code);
        stmt->setString(33,detail_item_voice.m_called_code);
        stmt->setString(34,detail_item_voice.m_user_type);
        stmt->setString(35,detail_item_voice.m_roam_type);
        stmt->setString(36,detail_item_voice.m_fee_type);
        stmt->setString(37,detail_item_voice.m_dial_type);
        stmt->setString(38,detail_item_voice.m_chat_type);
        stmt->setNumber(39,detail_item_voice.m_fee1);
        stmt->setNumber(40,detail_item_voice.m_fee2);
        stmt->setNumber(41,detail_item_voice.m_fee3);
        stmt->setNumber(42,detail_item_voice.m_old_fee1);
        stmt->setNumber(43,detail_item_voice.m_old_fee2);
        stmt->setNumber(44,detail_item_voice.m_old_fee3);
        stmt->setString(45,detail_item_voice.m_info_fee1);
        stmt->setString(46,detail_item_voice.m_info_fee2);
        stmt->setString(47,detail_item_voice.m_info_fee3);
        stmt->setString(48,detail_item_voice.m_file_name);
        stmt->setString(49,detail_item_voice.m_group_id);
        stmt->setString(50,detail_item_voice.m_product_code);
        stmt->setString(51,detail_item_voice.m_a_number);
        stmt->setString(52,detail_item_voice.m_brand_code);
        stmt->setString(53,detail_item_voice.m_roam_type_query);
        stmt->setString(54,detail_item_voice.m_fee_type_query);
        stmt->setString(55,detail_item_voice.m_dealfile);
        stmt->setString(56,detail_item_voice.m_error_code);
        stmt->setString(57,detail_item_voice.m_favour_fee1);
        stmt->setString(58,detail_item_voice.m_favour_fee2);
        stmt->setString(59,detail_item_voice.m_favour_fee3);
        stmt->setString(60,detail_item_voice.m_favour_flag);

    }
}

