#include "PaymentPlanDead.hh"

string PaymentPlanDead::insSQL="INSERT INTO PAYMENT_PLAN_DEAD(PAYMENT_PLAN_ID,ACCT_ID,PAYMENT_METHOD,PRIORITY,PAYMENT_PLAN_TYPE,PAYMENT_SUPPLIE_ID,PAYMENT_ACCT_NO,PAYMENT_ACCT_CUST_NAME,PAYMENT_ACCT_TYPE,STATE,STATE_DATE,DEAD_TIME,DEAD_STAFF_ID,DEAD_OPTSN)VALUES (:PAYMENT_PLAN_ID,:ACCT_ID,:PAYMENT_METHOD,:PRIORITY,:PAYMENT_PLAN_TYPE,:PAYMENT_SUPPLIE_ID,:PAYMENT_ACCT_NO,:PAYMENT_ACCT_CUST_NAME,:PAYMENT_ACCT_TYPE,:STATE,SYSDATE,SYSDATE,:DEAD_STAFF_ID,:DEAD_OPTSN)";

void PaymentPlanDead::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void PaymentPlanDead::prepareSQL()
{
    stmt->setNumber(1,payment_plan_dead.m_payment_plan_id);
    stmt->setNumber(2,payment_plan_dead.m_acct_id);
    stmt->setNumber(3,payment_plan_dead.m_payment_method);
    stmt->setNumber(4,payment_plan_dead.m_priority);
    stmt->setString(5,payment_plan_dead.m_payment_plan_type);
    stmt->setNumber(6,payment_plan_dead.m_payment_supplie_id);
    stmt->setString(7,payment_plan_dead.m_payment_acct_no);
    stmt->setString(8,payment_plan_dead.m_payment_acct_cust_name);
    stmt->setString(9,payment_plan_dead.m_payment_acct_type);
    stmt->setString(10,payment_plan_dead.m_state);
    stmt->setNumber(11,payment_plan_dead.m_dead_staff_id);
    stmt->setNumber(12,payment_plan_dead.m_dead_optsn);
}

