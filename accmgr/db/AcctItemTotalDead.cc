#include "AcctItemTotalDead.hh"

string AcctItemTotalDead::insSQL="INSERT INTO ACCT_ITEM_TOTAL_DEAD(AI_TOTAL_ID,ACCT_ID,SERV_ID,ACC_NBR,BILLING_CYCLE_ID,SHOULD_PAY,FAVOUR_FEE,TIMES,DURATION,AMOUNT,CREATED_DATE,STATE,STATE_DATE,MONTH_WRTOFF_FEE,PAY_WRTOFF_FEE,DEAD_TIME,DEAD_STAFF_ID,DEAD_OPTSN)VALUES (:AI_TOTAL_ID,:ACCT_ID,:SERV_ID,:ACC_NBR,:BILLING_CYCLE_ID,:SHOULD_PAY,:FAVOUR_FEE,:TIMES,:DURATION,:AMOUNT,SYSDATE,:STATE,SYSDATE,:MONTH_WRTOFF_FEE,:PAY_WRTOFF_FEE,SYSDATE,:DEAD_STAFF_ID,:DEAD_OPTSN)";

void AcctItemTotalDead::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void AcctItemTotalDead::prepareSQL()
{
    stmt->setNumber(1,acct_item_total_dead.m_ai_total_id);
    stmt->setNumber(2,acct_item_total_dead.m_acct_id);
    stmt->setNumber(3,acct_item_total_dead.m_serv_id);
    stmt->setString(4,acct_item_total_dead.m_acc_nbr);
    stmt->setNumber(5,acct_item_total_dead.m_billing_cycle_id);
    stmt->setNumber(6,acct_item_total_dead.m_should_pay);
    stmt->setNumber(7,acct_item_total_dead.m_favour_fee);
    stmt->setNumber(8,acct_item_total_dead.m_times);
    stmt->setNumber(9,acct_item_total_dead.m_duration);
    stmt->setNumber(10,acct_item_total_dead.m_amount);
    stmt->setString(11,acct_item_total_dead.m_state);
    stmt->setNumber(12,acct_item_total_dead.m_month_wrtoff_fee);
    stmt->setNumber(13,acct_item_total_dead.m_pay_wrtoff_fee);
    stmt->setNumber(14,acct_item_total_dead.m_dead_staff_id);
    stmt->setNumber(15,acct_item_total_dead.m_dead_optsn);
}

