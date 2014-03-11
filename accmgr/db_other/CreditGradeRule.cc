#include "CreditGradeRule.hh"

string CreditGradeRule::insSQL="INSERT INTO CREDIT_GRADE_RULE(CREDIT_GRADE_RULE_ID,CREDIT_GRADE_ID,CREDIT_CEIL,CREDIT_FLOOR,CREDIT_GRADE_NAME,EFF_DATE,EXP_DATE)VALUES (:CREDIT_GRADE_RULE_ID,:CREDIT_GRADE_ID,:CREDIT_CEIL,:CREDIT_FLOOR,:CREDIT_GRADE_NAME,SYSDATE,SYSDATE)";

void CreditGradeRule::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void CreditGradeRule::prepareSQL()
{
    stmt->setNumber(1,credit_grade_rule.m_credit_grade_rule_id);
    stmt->setNumber(2,credit_grade_rule.m_credit_grade_id);
    stmt->setNumber(3,credit_grade_rule.m_credit_ceil);
    stmt->setNumber(4,credit_grade_rule.m_credit_floor);
    stmt->setString(5,credit_grade_rule.m_credit_grade_name);
}

