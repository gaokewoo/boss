#include "ProductOfferParamInstance.hh"

string ProductOfferParamInstance::insSQL="INSERT INTO PRODUCT_OFFER_PARAM_INSTANCE(OFFER_PARAM_INSTANCE_ID,PRODUCT_OFFER_INSTANCE_ID,LIFE_CYCLE_ID,OFFER_PARAM_ID,PARAM_VALUE,PARAM_ATTR_ID)VALUES (:OFFER_PARAM_INSTANCE_ID,:PRODUCT_OFFER_INSTANCE_ID,:LIFE_CYCLE_ID,:OFFER_PARAM_ID,:PARAM_VALUE,:PARAM_ATTR_ID)";

void ProductOfferParamInstance::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void ProductOfferParamInstance::prepareSQL()
{
    stmt->setNumber(1,product_offer_param_instance.m_offer_param_instance_id);
    stmt->setNumber(2,product_offer_param_instance.m_product_offer_instance_id);
    stmt->setNumber(3,product_offer_param_instance.m_life_cycle_id);
    stmt->setNumber(4,product_offer_param_instance.m_offer_param_id);
    stmt->setString(5,product_offer_param_instance.m_param_value);
    stmt->setString(6,product_offer_param_instance.m_param_attr_id);
}

