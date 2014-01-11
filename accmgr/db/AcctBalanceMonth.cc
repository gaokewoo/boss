#include "AcctBalanceMonth.hh"

string AcctBalanceMonth::insSQL="INSERT INTO ACCT_BALANCE_MONTH(ACCT_BALANCE_ID,ACCT_ID,BALANCE_TYPE_ID,BALANCE,RESERVE_BALANCE,CYCLE_UPPER,CYCLE_LOWER,CYCLE_UPPER_TYPE,CYCLE_LOWER_TYPE,PAYMENT_DATE,BILL_MONTH_FLAG,EFF_DATE,EXP_DATE,STATE,STATE_DATE)VALUES (:ACCT_BALANCE_ID,:ACCT_ID,:BALANCE_TYPE_ID,:BALANCE,:RESERVE_BALANCE,:CYCLE_UPPER,:CYCLE_LOWER,:CYCLE_UPPER_TYPE,:CYCLE_LOWER_TYPE,SYSDATE,:BILL_MONTH_FLAG,SYSDATE,SYSDATE,:STATE,SYSDATE)";

void AcctBalanceMonth::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void AcctBalanceMonth::prepareSQL()
{
    stmt->setNumber(1,acct_balance_month.m_acct_balance_id);
    stmt->setNumber(2,acct_balance_month.m_acct_id);
    stmt->setNumber(3,acct_balance_month.m_balance_type_id);
    stmt->setNumber(4,acct_balance_month.m_balance);
    stmt->setNumber(5,acct_balance_month.m_reserve_balance);
    stmt->setNumber(6,acct_balance_month.m_cycle_upper);
    stmt->setNumber(7,acct_balance_month.m_cycle_lower);
    stmt->setString(8,acct_balance_month.m_cycle_upper_type);
    stmt->setString(9,acct_balance_month.m_cycle_lower_type);
    stmt->setString(10,acct_balance_month.m_bill_month_flag);
    stmt->setString(11,acct_balance_month.m_state);
}

