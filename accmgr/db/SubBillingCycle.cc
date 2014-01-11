#include "SubBillingCycle.hh"

string SubBillingCycle::insSQL="INSERT INTO SUB_BILLING_CYCLE(SUB_BILLING_CYCLE_ID,BILLING_CYCLE_ID,SUB_BILLING_CYCLE_TYPE,EFF_DATE,SUB_BILLING_CYCLE_DESC,EXP_DATE)VALUES (:SUB_BILLING_CYCLE_ID,:BILLING_CYCLE_ID,:SUB_BILLING_CYCLE_TYPE,SYSDATE,:SUB_BILLING_CYCLE_DESC,SYSDATE)";

void SubBillingCycle::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void SubBillingCycle::prepareSQL()
{
    stmt->setNumber(1,sub_billing_cycle.m_sub_billing_cycle_id);
    stmt->setNumber(2,sub_billing_cycle.m_billing_cycle_id);
    stmt->setString(3,sub_billing_cycle.m_sub_billing_cycle_type);
    stmt->setString(4,sub_billing_cycle.m_sub_billing_cycle_desc);
}

