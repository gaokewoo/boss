#include "EvalPlan.hh"

string EvalPlan::insSQL="INSERT INTO EVAL_PLAN(EVAL_PLAN_ID,EVAL_PLAN_NAME,EVAL_TYPE,EVAL_OBJECT_TYPE,EVAL_DESC)VALUES (:EVAL_PLAN_ID,:EVAL_PLAN_NAME,:EVAL_TYPE,:EVAL_OBJECT_TYPE,:EVAL_DESC)";

void EvalPlan::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void EvalPlan::prepareSQL()
{
    stmt->setNumber(1,eval_plan.m_eval_plan_id);
    stmt->setString(2,eval_plan.m_eval_plan_name);
    stmt->setString(3,eval_plan.m_eval_type);
    stmt->setString(4,eval_plan.m_eval_object_type);
    stmt->setString(5,eval_plan.m_eval_desc);
}

