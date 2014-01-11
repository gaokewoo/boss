#include "BillingCycle.hh"

string BillingCycle::insSQL="INSERT INTO BILLING_CYCLE(BILLING_CYCLE_ID,BILLING_CYCLE_TYPE_ID,CYCLE_BEGIN_DATE,CYCLE_END_DATE,DUE_DATE,BLOCK_DATE,LAST_BILLING_CYCLE_ID,STATE,STATE_DATE,BILL_MONTH_FLAG)VALUES (:BILLING_CYCLE_ID,:BILLING_CYCLE_TYPE_ID,SYSDATE,SYSDATE,SYSDATE,SYSDATE,:LAST_BILLING_CYCLE_ID,:STATE,SYSDATE,:BILL_MONTH_FLAG)";

void BillingCycle::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void BillingCycle::prepareSQL()
{
    stmt->setNumber(1,billing_cycle.m_billing_cycle_id);
    stmt->setNumber(2,billing_cycle.m_billing_cycle_type_id);
    stmt->setNumber(3,billing_cycle.m_last_billing_cycle_id);
    stmt->setString(4,billing_cycle.m_state);
    stmt->setString(5,billing_cycle.m_bill_month_flag);
}

