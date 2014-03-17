#include "ProductOfferParam.hh"

string ProductOfferParam::insSQL="INSERT INTO PRODUCT_OFFER_PARAM(OFFER_PARAM_ID,OFFER_ID,PARAM_ATTR_ID,PARAM_NAME,DEFAULT_VALUE)VALUES (:OFFER_PARAM_ID,:OFFER_ID,:PARAM_ATTR_ID,:PARAM_NAME,:DEFAULT_VALUE)";

void ProductOfferParam::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void ProductOfferParam::prepareSQL()
{
    stmt->setNumber(1,product_offer_param.m_offer_param_id);
    stmt->setNumber(2,product_offer_param.m_offer_id);
    stmt->setNumber(3,product_offer_param.m_param_attr_id);
    stmt->setString(4,product_offer_param.m_param_name);
    stmt->setString(5,product_offer_param.m_default_value);
}

