#include "BalanceRelation.hh"

string BalanceRelation::insSQL="INSERT INTO BALANCE_RELATION(BALANCE_RELATION_ID,ACCT_BALANCE_ID,OBJECT_TYPE,OBJECT_ID,PRIORITY,ATTACHED,STATE,STATE_DATE)VALUES (:BALANCE_RELATION_ID,:ACCT_BALANCE_ID,:OBJECT_TYPE,:OBJECT_ID,:PRIORITY,:ATTACHED,:STATE,SYSDATE)";

void BalanceRelation::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void BalanceRelation::prepareSQL()
{
    stmt->setNumber(1,balance_relation.m_balance_relation_id);
    stmt->setNumber(2,balance_relation.m_acct_balance_id);
    stmt->setString(3,balance_relation.m_object_type);
    stmt->setNumber(4,balance_relation.m_object_id);
    stmt->setNumber(5,balance_relation.m_priority);
    stmt->setString(6,balance_relation.m_attached);
    stmt->setString(7,balance_relation.m_state);
}

