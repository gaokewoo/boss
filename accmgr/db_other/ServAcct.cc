#include "ServAcct.hh"

string ServAcct::insSQL="INSERT INTO SERV_ACCT(SERV_ACCT_ID,ACCT_ID,SERV_ID,BILLING_CYCLE_TYPE_ID,ACCT_ITEM_GROUP_ID,PRIORITY,PAYMENT_RULE_ID,PAYMENT_LIMIT_TYPE,PAYMENT_LIMIT,STATE,STATE_DATE,PAY_PRIORITY,EFF_DATE,EXP_DATE)VALUES (:SERV_ACCT_ID,:ACCT_ID,:SERV_ID,:BILLING_CYCLE_TYPE_ID,:ACCT_ITEM_GROUP_ID,:PRIORITY,:PAYMENT_RULE_ID,:PAYMENT_LIMIT_TYPE,:PAYMENT_LIMIT,:STATE,SYSDATE,:PAY_PRIORITY,SYSDATE,SYSDATE)";

void ServAcct::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void ServAcct::prepareSQL()
{
    stmt->setNumber(1,serv_acct.m_serv_acct_id);
    stmt->setNumber(2,serv_acct.m_acct_id);
    stmt->setNumber(3,serv_acct.m_serv_id);
    stmt->setNumber(4,serv_acct.m_billing_cycle_type_id);
    stmt->setNumber(5,serv_acct.m_acct_item_group_id);
    stmt->setNumber(6,serv_acct.m_priority);
    stmt->setNumber(7,serv_acct.m_payment_rule_id);
    stmt->setString(8,serv_acct.m_payment_limit_type);
    stmt->setNumber(9,serv_acct.m_payment_limit);
    stmt->setString(10,serv_acct.m_state);
    stmt->setNumber(11,serv_acct.m_pay_priority);
}

