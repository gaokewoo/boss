#include "AcctBalance.hh"

string AcctBalance::insSQL="INSERT INTO ACCT_BALANCE(ACCT_BALANCE_ID,ACCT_ID,BALANCE_TYPE_ID,BALANCE,RESERVE_BALANCE,CYCLE_UPPER,CYCLE_LOWER,CYCLE_UPPER_TYPE,CYCLE_LOWER_TYPE,PAYMENT_DATE,BILL_MONTH_FLAG,EFF_DATE,EXP_DATE,STATE,STATE_DATE)VALUES (:ACCT_BALANCE_ID,:ACCT_ID,:BALANCE_TYPE_ID,:BALANCE,:RESERVE_BALANCE,:CYCLE_UPPER,:CYCLE_LOWER,:CYCLE_UPPER_TYPE,:CYCLE_LOWER_TYPE,SYSDATE,:BILL_MONTH_FLAG,SYSDATE,SYSDATE+3650,:STATE,SYSDATE)";

void AcctBalance::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void AcctBalance::prepareSQL()
{
    stmt->setNumber(1,acct_balance.m_acct_balance_id);
    stmt->setNumber(2,acct_balance.m_acct_id);
    stmt->setNumber(3,acct_balance.m_balance_type_id);
    stmt->setNumber(4,acct_balance.m_balance);
    stmt->setNumber(5,acct_balance.m_reserve_balance);
    stmt->setNumber(6,acct_balance.m_cycle_upper);
    stmt->setNumber(7,acct_balance.m_cycle_lower);
    stmt->setString(8,acct_balance.m_cycle_upper_type);
    stmt->setString(9,acct_balance.m_cycle_lower_type);
    stmt->setString(10,acct_balance.m_bill_month_flag);
    stmt->setString(11,acct_balance.m_state);
}

