#include "StopAcctServOwe.hh"

string StopAcctServOwe::insSQL="INSERT INTO STOP_ACCT_SERV_OWE(AI_TOTAL_ID,ACCT_ID,SERV_ID,ACC_NBR,BILLING_CYCLE_ID,AMOUNT,SHOULD_PAY,FAVOUR_FEE,TIMES,DURATION,CREATED_DATE,STATE,STATE_DATE,MONTH_WRTOFF_FEE,PAY_WRTOFF_FEE)VALUES (:AI_TOTAL_ID,:ACCT_ID,:SERV_ID,:ACC_NBR,:BILLING_CYCLE_ID,:AMOUNT,:SHOULD_PAY,:FAVOUR_FEE,:TIMES,:DURATION,SYSDATE,:STATE,SYSDATE,:MONTH_WRTOFF_FEE,:PAY_WRTOFF_FEE)";

void StopAcctServOwe::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void StopAcctServOwe::prepareSQL()
{
    stmt->setNumber(1,stop_acct_serv_owe.m_ai_total_id);
    stmt->setNumber(2,stop_acct_serv_owe.m_acct_id);
    stmt->setNumber(3,stop_acct_serv_owe.m_serv_id);
    stmt->setString(4,stop_acct_serv_owe.m_acc_nbr);
    stmt->setNumber(5,stop_acct_serv_owe.m_billing_cycle_id);
    stmt->setNumber(6,stop_acct_serv_owe.m_amount);
    stmt->setNumber(7,stop_acct_serv_owe.m_should_pay);
    stmt->setNumber(8,stop_acct_serv_owe.m_favour_fee);
    stmt->setNumber(9,stop_acct_serv_owe.m_times);
    stmt->setNumber(10,stop_acct_serv_owe.m_duration);
    stmt->setString(11,stop_acct_serv_owe.m_state);
    stmt->setNumber(12,stop_acct_serv_owe.m_month_wrtoff_fee);
    stmt->setNumber(13,stop_acct_serv_owe.m_pay_wrtoff_fee);
}

