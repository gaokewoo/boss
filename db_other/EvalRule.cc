#include "EvalRule.hh"

string EvalRule::insSQL="INSERT INTO EVAL_RULE(EVAL_RULE_ID,EVAL_RULE_NAME,TARGET_ID,EVAL_PLAN_ID,FACTOR_CATG_ID,DEFAULT_VALUE,PERCENTAGE,COMMENTS)VALUES (:EVAL_RULE_ID,:EVAL_RULE_NAME,:TARGET_ID,:EVAL_PLAN_ID,:FACTOR_CATG_ID,:DEFAULT_VALUE,:PERCENTAGE,:COMMENTS)";

void EvalRule::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void EvalRule::prepareSQL()
{
    stmt->setNumber(1,eval_rule.m_eval_rule_id);
    stmt->setString(2,eval_rule.m_eval_rule_name);
    stmt->setNumber(3,eval_rule.m_target_id);
    stmt->setNumber(4,eval_rule.m_eval_plan_id);
    stmt->setNumber(5,eval_rule.m_factor_catg_id);
    stmt->setNumber(6,eval_rule.m_default_value);
    stmt->setNumber(7,eval_rule.m_percentage);
    stmt->setString(8,eval_rule.m_comments);
}

