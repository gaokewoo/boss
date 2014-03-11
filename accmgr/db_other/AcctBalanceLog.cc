#include "AcctBalanceLog.hh"

string AcctBalanceLog::insSQL="INSERT INTO ACCT_BALANCE_LOG(BALANCE_LOG_ID,ACCT_BALANCE_ID,OPER_INCOME_ID,SRC_AMOUNT,OPER_PAYOUT_ID,PAYOUT_AMOUNT,BILLING_CYCLE_ID,STATE,STATE_DATE)VALUES (:BALANCE_LOG_ID,:ACCT_BALANCE_ID,:OPER_INCOME_ID,:SRC_AMOUNT,:OPER_PAYOUT_ID,:PAYOUT_AMOUNT,:BILLING_CYCLE_ID,:STATE,SYSDATE)";

void AcctBalanceLog::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void AcctBalanceLog::prepareSQL()
{
    stmt->setNumber(1,acct_balance_log.m_balance_log_id);
    stmt->setNumber(2,acct_balance_log.m_acct_balance_id);
    stmt->setNumber(3,acct_balance_log.m_oper_income_id);
    stmt->setNumber(4,acct_balance_log.m_src_amount);
    stmt->setNumber(5,acct_balance_log.m_oper_payout_id);
    stmt->setNumber(6,acct_balance_log.m_payout_amount);
    stmt->setNumber(7,acct_balance_log.m_billing_cycle_id);
    stmt->setString(8,acct_balance_log.m_state);
}

