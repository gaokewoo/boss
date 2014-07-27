#include "DetailItemCmsg.hh"

void DetailItemCmsg::insertData()
{
    type=INSERT;
    setSQL("INSERT INTO DETAIL_ITEM_CMSG(SYSTEM_TYPE,SM_TYPE,RECORD_TYPE,SERVICE_TYPE,SEG_NUM,IMSI,IMEI,MSISDN,OTHER_PARTY,START_DATETIME,END_DATETIME,CALL_DURATION,TIMES,DOWN_FLOW,UP_FLOW,TOTAL_FLOW,NAI,IP_ADDRESS,SP_CODE,SERV_CODE,OPER_CODE,BILLING_TYPE,RATE_UNIT,STATUS,SYS_ID,SYS_INTRA_KEY,SERVICE_ATTR,HOME_AREA_CODE,CHAT_TYPE,USER_TYPE,FEE1,FEE2,OLD_FEE1,OLD_FEE2,INFO_FEE1,INFO_FEE2,FILE_NAME,DEAL_TIME,GROUP_ID,PRODUCT_CODE,BRAND_CODE,DEALFILE)VALUES (:SYSTEM_TYPE,:SM_TYPE,:RECORD_TYPE,:SERVICE_TYPE,:SEG_NUM,:IMSI,:IMEI,:MSISDN,:OTHER_PARTY,SYSDATE,SYSDATE,:CALL_DURATION,:TIMES,:DOWN_FLOW,:UP_FLOW,:TOTAL_FLOW,:NAI,:IP_ADDRESS,:SP_CODE,:SERV_CODE,:OPER_CODE,:BILLING_TYPE,:RATE_UNIT,:STATUS,:SYS_ID,:SYS_INTRA_KEY,:SERVICE_ATTR,:HOME_AREA_CODE,:CHAT_TYPE,:USER_TYPE,:FEE1,:FEE2,:OLD_FEE1,:OLD_FEE2,:INFO_FEE1,:INFO_FEE2,:FILE_NAME,SYSDATE,:GROUP_ID,:PRODUCT_CODE,:BRAND_CODE,:DEALFILE)");
    executeUpdate();
}

void DetailItemCmsg::prepareSQL()
{
    if (type == INSERT)
    {
        stmt->setString(1,detail_item_cmsg.m_system_type);
        stmt->setString(2,detail_item_cmsg.m_sm_type);
        stmt->setString(3,detail_item_cmsg.m_record_type);
        stmt->setString(4,detail_item_cmsg.m_service_type);
        stmt->setString(5,detail_item_cmsg.m_seg_num);
        stmt->setString(6,detail_item_cmsg.m_imsi);
        stmt->setString(7,detail_item_cmsg.m_imei);
        stmt->setString(8,detail_item_cmsg.m_msisdn);
        stmt->setString(9,detail_item_cmsg.m_other_party);
        stmt->setNumber(10,detail_item_cmsg.m_call_duration);
        stmt->setNumber(11,detail_item_cmsg.m_times);
        stmt->setNumber(12,detail_item_cmsg.m_down_flow);
        stmt->setNumber(13,detail_item_cmsg.m_up_flow);
        stmt->setNumber(14,detail_item_cmsg.m_total_flow);
        stmt->setString(15,detail_item_cmsg.m_nai);
        stmt->setString(16,detail_item_cmsg.m_ip_address);
        stmt->setString(17,detail_item_cmsg.m_sp_code);
        stmt->setString(18,detail_item_cmsg.m_serv_code);
        stmt->setString(19,detail_item_cmsg.m_oper_code);
        stmt->setString(20,detail_item_cmsg.m_billing_type);
        stmt->setString(21,detail_item_cmsg.m_rate_unit);
        stmt->setString(22,detail_item_cmsg.m_status);
        stmt->setString(23,detail_item_cmsg.m_sys_id);
        stmt->setString(24,detail_item_cmsg.m_sys_intra_key);
        stmt->setString(25,detail_item_cmsg.m_service_attr);
        stmt->setString(26,detail_item_cmsg.m_home_area_code);
        stmt->setString(27,detail_item_cmsg.m_chat_type);
        stmt->setString(28,detail_item_cmsg.m_user_type);
        stmt->setNumber(29,detail_item_cmsg.m_fee1);
        stmt->setNumber(30,detail_item_cmsg.m_fee2);
        stmt->setNumber(31,detail_item_cmsg.m_old_fee1);
        stmt->setNumber(32,detail_item_cmsg.m_old_fee2);
        stmt->setString(33,detail_item_cmsg.m_info_fee1);
        stmt->setString(34,detail_item_cmsg.m_info_fee2);
        stmt->setString(35,detail_item_cmsg.m_file_name);
        stmt->setString(36,detail_item_cmsg.m_group_id);
        stmt->setString(37,detail_item_cmsg.m_product_code);
        stmt->setString(38,detail_item_cmsg.m_brand_code);
        stmt->setString(39,detail_item_cmsg.m_dealfile);

    }
}

