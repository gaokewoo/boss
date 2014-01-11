#include "AcctItemDead.hh"

string AcctItemDead::insSQL="INSERT INTO ACCT_ITEM_DEAD(ACCT_ITEM_ID,ITEM_SOURCE_ID,BILL_ID,ACCT_ITEM_TYPE_ID,BILLING_CYCLE_ID,ACCT_ID,SERV_ID,AMOUNT,CREATED_DATE,FEE_CYCLE_ID,PAYMENT_METHOD,STATE,STATE_DATE,LATN_ID,AI_TOTAL_ID,ACC_NBR,SHOULD_PAY,FAVOUR_FEE,TIMES,DURATION,MONTH_WRTOFF_FEE,PAY_WRTOFF_FEE,DEAD_TIME,DEAD_STAFF_ID,DEAD_OPTSN)VALUES (:ACCT_ITEM_ID,:ITEM_SOURCE_ID,:BILL_ID,:ACCT_ITEM_TYPE_ID,:BILLING_CYCLE_ID,:ACCT_ID,:SERV_ID,:AMOUNT,SYSDATE,:FEE_CYCLE_ID,:PAYMENT_METHOD,:STATE,SYSDATE,:LATN_ID,:AI_TOTAL_ID,:ACC_NBR,:SHOULD_PAY,:FAVOUR_FEE,:TIMES,:DURATION,:MONTH_WRTOFF_FEE,:PAY_WRTOFF_FEE,SYSDATE,:DEAD_STAFF_ID,:DEAD_OPTSN)";

void AcctItemDead::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void AcctItemDead::prepareSQL()
{
    stmt->setNumber(1,acct_item_dead.m_acct_item_id);
    stmt->setNumber(2,acct_item_dead.m_item_source_id);
    stmt->setNumber(3,acct_item_dead.m_bill_id);
    stmt->setNumber(4,acct_item_dead.m_acct_item_type_id);
    stmt->setNumber(5,acct_item_dead.m_billing_cycle_id);
    stmt->setNumber(6,acct_item_dead.m_acct_id);
    stmt->setNumber(7,acct_item_dead.m_serv_id);
    stmt->setNumber(8,acct_item_dead.m_amount);
    stmt->setNumber(9,acct_item_dead.m_fee_cycle_id);
    stmt->setNumber(10,acct_item_dead.m_payment_method);
    stmt->setString(11,acct_item_dead.m_state);
    stmt->setNumber(12,acct_item_dead.m_latn_id);
    stmt->setNumber(13,acct_item_dead.m_ai_total_id);
    stmt->setString(14,acct_item_dead.m_acc_nbr);
    stmt->setNumber(15,acct_item_dead.m_should_pay);
    stmt->setNumber(16,acct_item_dead.m_favour_fee);
    stmt->setNumber(17,acct_item_dead.m_times);
    stmt->setNumber(18,acct_item_dead.m_duration);
    stmt->setNumber(19,acct_item_dead.m_month_wrtoff_fee);
    stmt->setNumber(20,acct_item_dead.m_pay_wrtoff_fee);
    stmt->setNumber(21,acct_item_dead.m_dead_staff_id);
    stmt->setNumber(22,acct_item_dead.m_dead_optsn);
}

