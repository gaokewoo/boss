#include "BalanceRelationHis.hh"

string BalanceRelationHis::insSQL="INSERT INTO BALANCE_RELATION_HIS(BALANCE_RELATION_ID,ACCT_BALANCE_ID,OBJECT_TYPE,OBJECT_ID,PRIORITY,ATTACHED,HIS_DATE,STATE,STATE_DATE)VALUES (:BALANCE_RELATION_ID,:ACCT_BALANCE_ID,:OBJECT_TYPE,:OBJECT_ID,:PRIORITY,:ATTACHED,SYSDATE,:STATE,SYSDATE)";

void BalanceRelationHis::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void BalanceRelationHis::prepareSQL()
{
    stmt->setNumber(1,balance_relation_his.m_balance_relation_id);
    stmt->setNumber(2,balance_relation_his.m_acct_balance_id);
    stmt->setString(3,balance_relation_his.m_object_type);
    stmt->setNumber(4,balance_relation_his.m_object_id);
    stmt->setNumber(5,balance_relation_his.m_priority);
    stmt->setString(6,balance_relation_his.m_attached);
    stmt->setString(7,balance_relation_his.m_state);
}

