#include "PricingParamDefine.hh"

string PricingParamDefine::insSQL="INSERT INTO PRICING_PARAM_DEFINE(PRICING_PARAM_ID,PRICING_PARAM_NAME,DEFAULT_VALUE)VALUES (:PRICING_PARAM_ID,:PRICING_PARAM_NAME,:DEFAULT_VALUE)";

void PricingParamDefine::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void PricingParamDefine::prepareSQL()
{
    stmt->setNumber(1,pricing_param_define.m_pricing_param_id);
    stmt->setString(2,pricing_param_define.m_pricing_param_name);
    stmt->setString(3,pricing_param_define.m_default_value);
}

