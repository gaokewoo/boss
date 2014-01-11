#include "OweBusinessPlan.hh"

string OweBusinessPlan::insSQL="INSERT INTO OWE_BUSINESS_PLAN(REGION_CODE,PLAN_CODE,PLAN_NAME,STATE,STATE_DATE,PLAN_DESC)VALUES (:REGION_CODE,:PLAN_CODE,:PLAN_NAME,:STATE,SYSDATE,:PLAN_DESC)";

void OweBusinessPlan::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void OweBusinessPlan::prepareSQL()
{
    stmt->setString(1,owe_business_plan.m_region_code);
    stmt->setString(2,owe_business_plan.m_plan_code);
    stmt->setString(3,owe_business_plan.m_plan_name);
    stmt->setString(4,owe_business_plan.m_state);
    stmt->setString(5,owe_business_plan.m_plan_desc);
}

