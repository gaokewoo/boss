#include "InterestRate.hh"

string InterestRate::insSQL="INSERT INTO INTEREST_RATE(INTEREST_RATE_ID,LATN_ID,RATE)VALUES (:INTEREST_RATE_ID,:LATN_ID,:RATE)";

void InterestRate::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void InterestRate::prepareSQL()
{
    stmt->setNumber(1,interest_rate.m_interest_rate_id);
    stmt->setNumber(2,interest_rate.m_latn_id);
    stmt->setNumber(3,interest_rate.m_rate);
}

