#include "BalanceShareRuleDead.hh"

string BalanceShareRuleDead::insSQL="INSERT INTO BALANCE_SHARE_RULE_DEAD(SHARE_RULE_ID,ACCT_BALANCE_ID,SHARE_RULE_TYPE_ID,SHARE_RULE_TYPE_PRI,OBJECT_TYPE,OBJECT_ID,UPPER_AMOUNT,LOWER_AMOUNT,EFF_DATE,EXP_DATE,CALC_METHOD,DEAD_DATE)VALUES (:SHARE_RULE_ID,:ACCT_BALANCE_ID,:SHARE_RULE_TYPE_ID,:SHARE_RULE_TYPE_PRI,:OBJECT_TYPE,:OBJECT_ID,:UPPER_AMOUNT,:LOWER_AMOUNT,SYSDATE,SYSDATE,:CALC_METHOD,SYSDATE)";

void BalanceShareRuleDead::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void BalanceShareRuleDead::prepareSQL()
{
    stmt->setNumber(1,balance_share_rule_dead.m_share_rule_id);
    stmt->setNumber(2,balance_share_rule_dead.m_acct_balance_id);
    stmt->setNumber(3,balance_share_rule_dead.m_share_rule_type_id);
    stmt->setNumber(4,balance_share_rule_dead.m_share_rule_type_pri);
    stmt->setString(5,balance_share_rule_dead.m_object_type);
    stmt->setNumber(6,balance_share_rule_dead.m_object_id);
    stmt->setNumber(7,balance_share_rule_dead.m_upper_amount);
    stmt->setNumber(8,balance_share_rule_dead.m_lower_amount);
    stmt->setString(9,balance_share_rule_dead.m_calc_method);
}

