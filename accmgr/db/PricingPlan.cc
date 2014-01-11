#include "PricingPlan.hh"

string PricingPlan::insSQL="INSERT INTO PRICING_PLAN(PRICING_PLAN_ID,PRICING_PLAN_NAME,PRICING_DESC,PARAM_DESC)VALUES (:PRICING_PLAN_ID,:PRICING_PLAN_NAME,:PRICING_DESC,:PARAM_DESC)";

void PricingPlan::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void PricingPlan::prepareSQL()
{
    stmt->setNumber(1,pricing_plan.m_pricing_plan_id);
    stmt->setString(2,pricing_plan.m_pricing_plan_name);
    stmt->setString(3,pricing_plan.m_pricing_desc);
    stmt->setString(4,pricing_plan.m_param_desc);
}

