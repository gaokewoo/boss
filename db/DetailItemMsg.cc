#include "DetailItemMsg.hh"
#include "Dual.hh"

void DetailItemMsg::insertData()
{
    type=INSERT;

    Dual dual;
    dual.setConnection(conn);
    string m_ym = dual.getSysDateYYYYMM();

    setSQL("INSERT INTO DETAIL_ITEM_MSG"+m_ym+"(SYSTEM_TYPE,ISM_TYPE,SM_TYPE,MSG_ID,IMSI,IMEI,MSISDN,OTHER_PARTY,START_DATETIME,END_DATETIME,MSG_LENGTH,STATUS,PRIORITY,GATEWAY_CODE,F_GATEWAY_CODE,SERV_CODE,SM_CENTER_CODE,BILLING_FLAG,SERVICE_ATTR,HOME_AREA_CODE,USER_TYPE,FEE1,OLD_FEE1,INFO_FEE1,FILE_NAME,DEAL_TIME,GROUP_ID,PRODUCT_CODE,CHAT_TYPE,BRAND_CODE,DEALFILE)VALUES (:SYSTEM_TYPE,:ISM_TYPE,:SM_TYPE,:MSG_ID,:IMSI,:IMEI,:MSISDN,:OTHER_PARTY,SYSDATE,SYSDATE,:MSG_LENGTH,:STATUS,:PRIORITY,:GATEWAY_CODE,:F_GATEWAY_CODE,:SERV_CODE,:SM_CENTER_CODE,:BILLING_FLAG,:SERVICE_ATTR,:HOME_AREA_CODE,:USER_TYPE,:FEE1,:OLD_FEE1,:INFO_FEE1,:FILE_NAME,SYSDATE,:GROUP_ID,:PRODUCT_CODE,:CHAT_TYPE,:BRAND_CODE,:DEALFILE)");
    executeUpdate();
}

void DetailItemMsg::prepareSQL()
{
    if (type == INSERT)
    {
        stmt->setString(1,detail_item_msg.m_system_type);
        stmt->setString(2,detail_item_msg.m_ism_type);
        stmt->setString(3,detail_item_msg.m_sm_type);
        stmt->setString(4,detail_item_msg.m_msg_id);
        stmt->setString(5,detail_item_msg.m_imsi);
        stmt->setString(6,detail_item_msg.m_imei);
        stmt->setString(7,detail_item_msg.m_msisdn);
        stmt->setString(8,detail_item_msg.m_other_party);
        stmt->setNumber(9,detail_item_msg.m_msg_length);
        stmt->setString(10,detail_item_msg.m_status);
        stmt->setString(11,detail_item_msg.m_priority);
        stmt->setString(12,detail_item_msg.m_gateway_code);
        stmt->setString(13,detail_item_msg.m_f_gateway_code);
        stmt->setString(14,detail_item_msg.m_serv_code);
        stmt->setString(15,detail_item_msg.m_sm_center_code);
        stmt->setString(16,detail_item_msg.m_billing_flag);
        stmt->setString(17,detail_item_msg.m_service_attr);
        stmt->setString(18,detail_item_msg.m_home_area_code);
        stmt->setString(19,detail_item_msg.m_user_type);
        stmt->setNumber(20,detail_item_msg.m_fee1);
        stmt->setNumber(21,detail_item_msg.m_old_fee1);
        stmt->setString(22,detail_item_msg.m_info_fee1);
        stmt->setString(23,detail_item_msg.m_file_name);
        stmt->setString(24,detail_item_msg.m_group_id);
        stmt->setString(25,detail_item_msg.m_product_code);
        stmt->setString(26,detail_item_msg.m_chat_type);
        stmt->setString(27,detail_item_msg.m_brand_code);
        stmt->setString(28,detail_item_msg.m_dealfile);

    }
}

