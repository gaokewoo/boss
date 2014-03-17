#include "InterestBalance.hh"

string InterestBalance::insSQL="INSERT INTO INTEREST_BALANCE(ACCT_BALANCE_ID,INTEREST_BALANCE_TOTAL,INTEREST_BALANCE_AMOUNT,INTEREST_CHANGE_VALUE,CALC_BEGIN_YMD,CALC_END_YMD,CURR_BALANCE,INTEREST_RATE_ID,STAFF_ID,OPER_TIME)VALUES (:ACCT_BALANCE_ID,:INTEREST_BALANCE_TOTAL,:INTEREST_BALANCE_AMOUNT,:INTEREST_CHANGE_VALUE,:CALC_BEGIN_YMD,:CALC_END_YMD,:CURR_BALANCE,:INTEREST_RATE_ID,:STAFF_ID,SYSDATE)";

void InterestBalance::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void InterestBalance::prepareSQL()
{
    stmt->setNumber(1,interest_balance.m_acct_balance_id);
    stmt->setNumber(2,interest_balance.m_interest_balance_total);
    stmt->setNumber(3,interest_balance.m_interest_balance_amount);
    stmt->setNumber(4,interest_balance.m_interest_change_value);
    stmt->setNumber(5,interest_balance.m_calc_begin_ymd);
    stmt->setNumber(6,interest_balance.m_calc_end_ymd);
    stmt->setNumber(7,interest_balance.m_curr_balance);
    stmt->setNumber(8,interest_balance.m_interest_rate_id);
    stmt->setNumber(9,interest_balance.m_staff_id);
}

