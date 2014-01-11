#include "PricingEnumParam.hh"

string PricingEnumParam::insSQL="INSERT INTO PRICING_ENUM_PARAM(ENUM_ID,PRICING_PARAM_ID,PARAM_VALUE)VALUES (:ENUM_ID,:PRICING_PARAM_ID,:PARAM_VALUE)";

void PricingEnumParam::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void PricingEnumParam::prepareSQL()
{
    stmt->setNumber(1,pricing_enum_param.m_enum_id);
    stmt->setNumber(2,pricing_enum_param.m_pricing_param_id);
    stmt->setString(3,pricing_enum_param.m_param_value);
}

