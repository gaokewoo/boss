#include "DetailItemCring.hh"
#include "Dual.hh"

void DetailItemCring::insertData()
{
    type=INSERT;

    Dual dual;
    dual.setConnection(conn);
    string m_ym = dual.getSysDateYYYYMM();

    setSQL("INSERT INTO DETAIL_ITEM_CRING"+m_ym+"(SYSTEM_TYPE,RECORD_TYPE,CALL_TYPE,MSISDN,OTHER_PARTY,START_DATETIME,END_DATETIME,CALL_DURATION,RECORD_GEN_TYPE,SERVICE_KEY,SERVICE_ID,SP_CODE,SERV_CODE,OPER_CODE,HOME_AREA_CODE,BILLING_TYPE,USER_LEVEL,USER_TYPE,BRAND_CODE,ROAM_TYPE,FEE_TYPE,FEE1,FEE2,FEE3,OLD_FEE1,OLD_FEE2,OLD_FEE3,INFO_FEE1,INFO_FEE2,INFO_FEE3,FILE_NAME,DEAL_TIME,GROUP_ID,PRODUCT_CODE,DEALFILE)VALUES (:SYSTEM_TYPE,:RECORD_TYPE,:CALL_TYPE,:MSISDN,:OTHER_PARTY,SYSDATE,SYSDATE,:CALL_DURATION,:RECORD_GEN_TYPE,:SERVICE_KEY,:SERVICE_ID,:SP_CODE,:SERV_CODE,:OPER_CODE,:HOME_AREA_CODE,:BILLING_TYPE,:USER_LEVEL,:USER_TYPE,:BRAND_CODE,:ROAM_TYPE,:FEE_TYPE,:FEE1,:FEE2,:FEE3,:OLD_FEE1,:OLD_FEE2,:OLD_FEE3,:INFO_FEE1,:INFO_FEE2,:INFO_FEE3,:FILE_NAME,SYSDATE,:GROUP_ID,:PRODUCT_CODE,:DEALFILE)");
    executeUpdate();
}

void DetailItemCring::prepareSQL()
{
    if (type == INSERT)
    {
        stmt->setString(1,detail_item_cring.m_system_type);
        stmt->setString(2,detail_item_cring.m_record_type);
        stmt->setString(3,detail_item_cring.m_call_type);
        stmt->setString(4,detail_item_cring.m_msisdn);
        stmt->setString(5,detail_item_cring.m_other_party);
        stmt->setString(6,detail_item_cring.m_call_duration);
        stmt->setString(7,detail_item_cring.m_record_gen_type);
        stmt->setString(8,detail_item_cring.m_service_key);
        stmt->setString(9,detail_item_cring.m_service_id);
        stmt->setString(10,detail_item_cring.m_sp_code);
        stmt->setString(11,detail_item_cring.m_serv_code);
        stmt->setString(12,detail_item_cring.m_oper_code);
        stmt->setString(13,detail_item_cring.m_home_area_code);
        stmt->setString(14,detail_item_cring.m_billing_type);
        stmt->setString(15,detail_item_cring.m_user_level);
        stmt->setString(16,detail_item_cring.m_user_type);
        stmt->setString(17,detail_item_cring.m_brand_code);
        stmt->setString(18,detail_item_cring.m_roam_type);
        stmt->setString(19,detail_item_cring.m_fee_type);
        stmt->setString(20,detail_item_cring.m_fee1);
        stmt->setString(21,detail_item_cring.m_fee2);
        stmt->setString(22,detail_item_cring.m_fee3);
        stmt->setString(23,detail_item_cring.m_old_fee1);
        stmt->setString(24,detail_item_cring.m_old_fee2);
        stmt->setString(25,detail_item_cring.m_old_fee3);
        stmt->setString(26,detail_item_cring.m_info_fee1);
        stmt->setString(27,detail_item_cring.m_info_fee2);
        stmt->setString(28,detail_item_cring.m_info_fee3);
        stmt->setString(29,detail_item_cring.m_file_name);
        stmt->setString(30,detail_item_cring.m_group_id);
        stmt->setString(31,detail_item_cring.m_product_code);
        stmt->setString(32,detail_item_cring.m_dealfile);

    }
}

