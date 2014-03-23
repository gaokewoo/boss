#include "BillingCycle.hh"

string BillingCycle::insSQL="INSERT INTO BILLING_CYCLE(BILLING_CYCLE_ID,BILLING_CYCLE_TYPE_ID,CYCLE_BEGIN_DATE,CYCLE_END_DATE,DUE_DATE,BLOCK_DATE,LAST_BILLING_CYCLE_ID,STATE,STATE_DATE,BILL_MONTH_FLAG)VALUES (:BILLING_CYCLE_ID,:BILLING_CYCLE_TYPE_ID,SYSDATE,LAST_DAY(SYSDATE),SYSDATE,SYSDATE,:LAST_BILLING_CYCLE_ID,:STATE,SYSDATE,:BILL_MONTH_FLAG)";

string BillingCycle::emptySQL="DELETE FROM BILLING_CYCLE";

string BillingCycle::selectAllSQL="SELECT BILLING_CYCLE_ID,BILLING_CYCLE_TYPE_ID,TO_CHAR(CYCLE_BEGIN_DATE,'YYYYMMDDHH24MISS'),TO_CHAR(CYCLE_END_DATE,'YYYYMMDDHH24MISS'),TO_CHAR(DUE_DATE,'YYYYMMDDHH24MISS'),TO_CHAR(BLOCK_DATE,'YYYYMMDDHH24MISS'),LAST_BILLING_CYCLE_ID,STATE,TO_CHAR(STATE_DATE,'YYYYMMDDHH24MISS'),BILL_MONTH_FLAG FROM BILLING_CYCLE";

void BillingCycle::insertData()
{
    type=0;
    setSQL(insSQL);
    executeUpdate();
}

void BillingCycle::emptyData()
{
    type=1;
    setSQL(emptySQL);
    executeUpdate();
}

vector<ST_BILLING_CYCLE> BillingCycle::loadAllData()
{
    type=2;
    setSQL(selectAllSQL);
    executeQuery();

    return v_data;
}

vector<ST_BILLING_CYCLE> BillingCycle::getEffectiveBillingCycle()
{
    type=3;
    string selSQL="SELECT BILLING_CYCLE_ID,BILLING_CYCLE_TYPE_ID,TO_CHAR(CYCLE_BEGIN_DATE,'YYYYMMDDHH24MISS'),TO_CHAR(CYCLE_END_DATE,'YYYYMMDDHH24MISS'),TO_CHAR(DUE_DATE,'YYYYMMDDHH24MISS'),TO_CHAR(BLOCK_DATE,'YYYYMMDDHH24MISS'),LAST_BILLING_CYCLE_ID,STATE,TO_CHAR(STATE_DATE,'YYYYMMDDHH24MISS'),BILL_MONTH_FLAG FROM BILLING_CYCLE WHERE STATE='00A'";

    setSQL(selSQL);

    executeQuery();

    return v_data;
}

void BillingCycle::doParse()
{
    billing_cycle.m_billing_cycle_id = (long)rset->getNumber(1);
    billing_cycle.m_billing_cycle_type_id = (long)rset->getNumber(2);
    billing_cycle.m_cycle_begin_date = rset->getString(3);
    billing_cycle.m_cycle_end_date = rset->getString(4);
    billing_cycle.m_due_date = rset->getString(5);
    billing_cycle.m_block_date = rset->getString(6);
    billing_cycle.m_last_billing_cycle_id = (long)rset->getNumber(7);
    billing_cycle.m_state = rset->getString(8);
    billing_cycle.m_state_date = rset->getString(9);
    billing_cycle.m_bill_month_flag = rset->getString(10);

    v_data.push_back(billing_cycle);
}

void BillingCycle::prepareSQL()
{
    if (type == 0)
    {
    stmt->setNumber(1,billing_cycle.m_billing_cycle_id);
    stmt->setNumber(2,billing_cycle.m_billing_cycle_type_id);
    stmt->setNumber(3,billing_cycle.m_last_billing_cycle_id);
    stmt->setString(4,billing_cycle.m_state);
    stmt->setString(5,billing_cycle.m_bill_month_flag);
    }
}

