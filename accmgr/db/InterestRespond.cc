#include "InterestRespond.hh"

string InterestRespond::insSQL="INSERT INTO INTEREST_RESPOND(INTEREST_INFO_ID,ACCT_BALANCE_ID,CHARGE,DATE,STATE)VALUES (:INTEREST_INFO_ID,:ACCT_BALANCE_ID,:CHARGE,SYSDATE,:STATE)";

void InterestRespond::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void InterestRespond::prepareSQL()
{
    stmt->setNumber(1,interest_respond.m_interest_info_id);
    stmt->setNumber(2,interest_respond.m_acct_balance_id);
    stmt->setNumber(3,interest_respond.m_charge);
    stmt->setString(4,interest_respond.m_state);
}

