#include "ProductOfferInstanceAttr.hh"

string ProductOfferInstanceAttr::insSQL="INSERT INTO PRODUCT_OFFER_INSTANCE_ATTR(SERV_ID,ATTR_ID,AGREEMENT_ID,OFFER_ID,ATTR_VAL,EFF_DATE,EXP_DATE,CREATE_DATE,STATE_CD,STATE_DATE)VALUES (:SERV_ID,:ATTR_ID,:AGREEMENT_ID,:OFFER_ID,:ATTR_VAL,SYSDATE,SYSDATE,SYSDATE,:STATE_CD,SYSDATE)";

void ProductOfferInstanceAttr::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void ProductOfferInstanceAttr::prepareSQL()
{
    stmt->setNumber(1,product_offer_instance_attr.m_serv_id);
    stmt->setNumber(2,product_offer_instance_attr.m_attr_id);
    stmt->setNumber(3,product_offer_instance_attr.m_agreement_id);
    stmt->setNumber(4,product_offer_instance_attr.m_offer_id);
    stmt->setString(5,product_offer_instance_attr.m_attr_val);
    stmt->setString(6,product_offer_instance_attr.m_state_cd);
}

