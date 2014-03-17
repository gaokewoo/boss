#include "BalanceRelationDead.hh"

string BalanceRelationDead::insSQL="INSERT INTO BALANCE_RELATION_DEAD(BALANCE_RELATION_ID,ACCT_BALANCE_ID,OBJECT_TYPE,OBJECT_ID,PRIORITY,ATTACHED,DEAD_TIME,DEAD_STAFF_ID,DEAD_OPTSN,STATE,STATE_DATE)VALUES (:BALANCE_RELATION_ID,:ACCT_BALANCE_ID,:OBJECT_TYPE,:OBJECT_ID,:PRIORITY,:ATTACHED,SYSDATE,:DEAD_STAFF_ID,:DEAD_OPTSN,:STATE,SYSDATE)";

void BalanceRelationDead::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void BalanceRelationDead::prepareSQL()
{
    stmt->setNumber(1,balance_relation_dead.m_balance_relation_id);
    stmt->setNumber(2,balance_relation_dead.m_acct_balance_id);
    stmt->setString(3,balance_relation_dead.m_object_type);
    stmt->setNumber(4,balance_relation_dead.m_object_id);
    stmt->setNumber(5,balance_relation_dead.m_priority);
    stmt->setString(6,balance_relation_dead.m_attached);
    stmt->setNumber(7,balance_relation_dead.m_dead_staff_id);
    stmt->setNumber(8,balance_relation_dead.m_dead_optsn);
    stmt->setString(9,balance_relation_dead.m_state);
}

