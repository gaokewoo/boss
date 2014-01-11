#include "ProductOfferInstance.hh"

string ProductOfferInstance::insSQL="INSERT INTO PRODUCT_OFFER_INSTANCE(PRODUCT_OFFER_INSTANCE_ID,CUST_ID,CUST_AGREEMENT_ID,OFFER_ID,STATE,STATE_DATE,EFF_DATE,EXP_DATE,PRIORITY,HANDLE_STAFF_ID,DEVELOP_STAFF_ID,CHANNEL_ID,REL_OFFER_INST_ID,GROUP_ID,SERV_ID)VALUES (:PRODUCT_OFFER_INSTANCE_ID,:CUST_ID,:CUST_AGREEMENT_ID,:OFFER_ID,:STATE,SYSDATE,SYSDATE,SYSDATE,:PRIORITY,:HANDLE_STAFF_ID,:DEVELOP_STAFF_ID,:CHANNEL_ID,:REL_OFFER_INST_ID,:GROUP_ID,:SERV_ID)";

void ProductOfferInstance::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void ProductOfferInstance::prepareSQL()
{
    stmt->setNumber(1,product_offer_instance.m_product_offer_instance_id);
    stmt->setNumber(2,product_offer_instance.m_cust_id);
    stmt->setNumber(3,product_offer_instance.m_cust_agreement_id);
    stmt->setNumber(4,product_offer_instance.m_offer_id);
    stmt->setString(5,product_offer_instance.m_state);
    stmt->setNumber(6,product_offer_instance.m_priority);
    stmt->setNumber(7,product_offer_instance.m_handle_staff_id);
    stmt->setNumber(8,product_offer_instance.m_develop_staff_id);
    stmt->setString(9,product_offer_instance.m_channel_id);
    stmt->setNumber(10,product_offer_instance.m_rel_offer_inst_id);
    stmt->setNumber(11,product_offer_instance.m_group_id);
    stmt->setNumber(12,product_offer_instance.m_serv_id);
}

