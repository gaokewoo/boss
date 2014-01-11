#include "BillingCycleType.hh"

string BillingCycleType::insSQL="INSERT INTO BILLING_CYCLE_TYPE(BILLING_CYCLE_TYPE_ID,BILLING_CYCLE_TYPE_NAME,APP_TYPE,CYCLE_UNIT,UNIT_COUNT,CYCLE_DURATION,CYCLE_DURATION_DAYS)VALUES (:BILLING_CYCLE_TYPE_ID,:BILLING_CYCLE_TYPE_NAME,:APP_TYPE,:CYCLE_UNIT,:UNIT_COUNT,:CYCLE_DURATION,:CYCLE_DURATION_DAYS)";

void BillingCycleType::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void BillingCycleType::prepareSQL()
{
    stmt->setNumber(1,billing_cycle_type.m_billing_cycle_type_id);
    stmt->setString(2,billing_cycle_type.m_billing_cycle_type_name);
    stmt->setString(3,billing_cycle_type.m_app_type);
    stmt->setString(4,billing_cycle_type.m_cycle_unit);
    stmt->setNumber(5,billing_cycle_type.m_unit_count);
    stmt->setNumber(6,billing_cycle_type.m_cycle_duration);
    stmt->setNumber(7,billing_cycle_type.m_cycle_duration_days);
}

