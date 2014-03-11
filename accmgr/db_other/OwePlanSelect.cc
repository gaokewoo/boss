#include "OwePlanSelect.hh"

string OwePlanSelect::insSQL="INSERT INTO OWE_PLAN_SELECT(REGION_CODE,SM_CODE,OPERATE_TYPE,OPERATE_CODE,PLAN_CODE,STATE,STATE_DATE)VALUES (:REGION_CODE,:SM_CODE,:OPERATE_TYPE,:OPERATE_CODE,:PLAN_CODE,:STATE,SYSDATE)";

void OwePlanSelect::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void OwePlanSelect::prepareSQL()
{
    stmt->setString(1,owe_plan_select.m_region_code);
    stmt->setString(2,owe_plan_select.m_sm_code);
    stmt->setString(3,owe_plan_select.m_operate_type);
    stmt->setString(4,owe_plan_select.m_operate_code);
    stmt->setString(5,owe_plan_select.m_plan_code);
    stmt->setString(6,owe_plan_select.m_state);
}

