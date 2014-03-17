#include "ServAcctDead.hh"

string ServAcctDead::insSQL="INSERT INTO SERV_ACCT_DEAD(SERV_ACCT_ID,ACCT_ID,SERV_ID,BILLING_CYCLE_TYPE_ID,ACCT_ITEM_GROUP_ID,PRIORITY,PAYMENT_RULE_ID,PAYMENT_LIMIT_TYPE,PAYMENT_LIMIT,STATE,STATE_DATE,PAY_PRIORITY,EFF_DATE,EXP_DATE,DEAD_TIME,DEAD_STAFF_ID,DEAD_OPTSN)VALUES (:SERV_ACCT_ID,:ACCT_ID,:SERV_ID,:BILLING_CYCLE_TYPE_ID,:ACCT_ITEM_GROUP_ID,:PRIORITY,:PAYMENT_RULE_ID,:PAYMENT_LIMIT_TYPE,:PAYMENT_LIMIT,:STATE,SYSDATE,:PAY_PRIORITY,SYSDATE,SYSDATE,SYSDATE,:DEAD_STAFF_ID,:DEAD_OPTSN)";

void ServAcctDead::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void ServAcctDead::prepareSQL()
{
    stmt->setNumber(1,serv_acct_dead.m_serv_acct_id);
    stmt->setNumber(2,serv_acct_dead.m_acct_id);
    stmt->setNumber(3,serv_acct_dead.m_serv_id);
    stmt->setNumber(4,serv_acct_dead.m_billing_cycle_type_id);
    stmt->setNumber(5,serv_acct_dead.m_acct_item_group_id);
    stmt->setNumber(6,serv_acct_dead.m_priority);
    stmt->setNumber(7,serv_acct_dead.m_payment_rule_id);
    stmt->setString(8,serv_acct_dead.m_payment_limit_type);
    stmt->setNumber(9,serv_acct_dead.m_payment_limit);
    stmt->setString(10,serv_acct_dead.m_state);
    stmt->setNumber(11,serv_acct_dead.m_pay_priority);
    stmt->setNumber(12,serv_acct_dead.m_dead_staff_id);
    stmt->setNumber(13,serv_acct_dead.m_dead_optsn);
}

