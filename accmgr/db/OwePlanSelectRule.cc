#include "OwePlanSelectRule.hh"

string OwePlanSelectRule::insSQL="INSERT INTO OWE_PLAN_SELECT_RULE(OP_TYPE,OP_CODE,OPERATE_TYPE,OPERATE_ORDER,TYPE_FLAG,TYPE_NAME)VALUES (:OP_TYPE,:OP_CODE,:OPERATE_TYPE,:OPERATE_ORDER,:TYPE_FLAG,:TYPE_NAME)";

void OwePlanSelectRule::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void OwePlanSelectRule::prepareSQL()
{
    stmt->setString(1,owe_plan_select_rule.m_op_type);
    stmt->setString(2,owe_plan_select_rule.m_op_code);
    stmt->setString(3,owe_plan_select_rule.m_operate_type);
    stmt->setNumber(4,owe_plan_select_rule.m_operate_order);
    stmt->setNumber(5,owe_plan_select_rule.m_type_flag);
    stmt->setString(6,owe_plan_select_rule.m_type_name);
}

