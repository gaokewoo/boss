#include "BillingCycleType.hh"

string BillingCycleType::insSQL="INSERT INTO BILLING_CYCLE_TYPE(BILLING_CYCLE_TYPE_ID,BILLING_CYCLE_TYPE_NAME,APP_TYPE,CYCLE_UNIT,UNIT_COUNT,CYCLE_DURATION,CYCLE_DURATION_DAYS)VALUES (:BILLING_CYCLE_TYPE_ID,:BILLING_CYCLE_TYPE_NAME,:APP_TYPE,:CYCLE_UNIT,:UNIT_COUNT,:CYCLE_DURATION,:CYCLE_DURATION_DAYS)";

string BillingCycleType::emptySQL="DELETE FROM BILLING_CYCLE_TYPE";

string BillingCycleType::selectAllSQL="SELECT BILLING_CYCLE_TYPE_ID,BILLING_CYCLE_TYPE_NAME,APP_TYPE,CYCLE_UNIT,UNIT_COUNT,CYCLE_DURATION,CYCLE_DURATION_DAYS FROM BILLING_CYCLE_TYPE";

void BillingCycleType::insertData()
{
    type=0;
    setSQL(insSQL);
    executeUpdate();
}

void BillingCycleType::emptyData()
{
    type=1;
    setSQL(emptySQL);
    executeUpdate();
}

vector<ST_BILLING_CYCLE_TYPE> BillingCycleType::loadAllData()
{
    type=2;
    setSQL(selectAllSQL);
    executeQuery();

    return v_data;
}

void BillingCycleType::doParse()
{
    billing_cycle_type.m_billing_cycle_type_id = (long)rset->getNumber(1);
    billing_cycle_type.m_billing_cycle_type_name = rset->getString(2);
    billing_cycle_type.m_app_type = rset->getString(3);
    billing_cycle_type.m_cycle_unit = rset->getString(4);
    billing_cycle_type.m_unit_count = (long)rset->getNumber(5);
    billing_cycle_type.m_cycle_duration = (long)rset->getNumber(6);
    billing_cycle_type.m_cycle_duration_days = (long)rset->getNumber(7);

    v_data.push_back(billing_cycle_type);
}

void BillingCycleType::prepareSQL()
{
    if (type == 0)
    {
    stmt->setNumber(1,billing_cycle_type.m_billing_cycle_type_id);
    stmt->setString(2,billing_cycle_type.m_billing_cycle_type_name);
    stmt->setString(3,billing_cycle_type.m_app_type);
    stmt->setString(4,billing_cycle_type.m_cycle_unit);
    stmt->setNumber(5,billing_cycle_type.m_unit_count);
    stmt->setNumber(6,billing_cycle_type.m_cycle_duration);
    stmt->setNumber(7,billing_cycle_type.m_cycle_duration_days);
    }
}

