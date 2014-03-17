#include "PaymentPlan.hh"

string PaymentPlan::insSQL="INSERT INTO PAYMENT_PLAN(PAYMENT_PLAN_ID,ACCT_ID,PAYMENT_METHOD,PRIORITY,PAYMENT_PLAN_TYPE,PAYMENT_SUPPLIE_ID,PAYMENT_ACCT_NO,PAYMENT_ACCT_CUST_NAME,PAYMENT_ACCT_TYPE,STATE,STATE_DATE)VALUES (:PAYMENT_PLAN_ID,:ACCT_ID,:PAYMENT_METHOD,:PRIORITY,:PAYMENT_PLAN_TYPE,:PAYMENT_SUPPLIE_ID,:PAYMENT_ACCT_NO,:PAYMENT_ACCT_CUST_NAME,:PAYMENT_ACCT_TYPE,:STATE,SYSDATE)";

void PaymentPlan::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void PaymentPlan::prepareSQL()
{
    stmt->setNumber(1,payment_plan.m_payment_plan_id);
    stmt->setNumber(2,payment_plan.m_acct_id);
    stmt->setNumber(3,payment_plan.m_payment_method);
    stmt->setNumber(4,payment_plan.m_priority);
    stmt->setString(5,payment_plan.m_payment_plan_type);
    stmt->setNumber(6,payment_plan.m_payment_supplie_id);
    stmt->setString(7,payment_plan.m_payment_acct_no);
    stmt->setString(8,payment_plan.m_payment_acct_cust_name);
    stmt->setString(9,payment_plan.m_payment_acct_type);
    stmt->setString(10,payment_plan.m_state);
}

