#include "AcctItem.hh"

string AcctItem::insSQL="INSERT INTO ACCT_ITEM(ACCT_ITEM_ID,ITEM_SOURCE_ID,BILL_ID,ACCT_ITEM_TYPE_ID,BILLING_CYCLE_ID,ACCT_ID,SERV_ID,AMOUNT,CREATED_DATE,FEE_CYCLE_ID,PAYMENT_METHOD,STATE,STATE_DATE,LATN_ID,AI_TOTAL_ID,ACC_NBR,SHOULD_PAY,FAVOUR_FEE,TIMES,DURATION,MONTH_WRTOFF_FEE,PAY_WRTOFF_FEE,ATTR_CODE)VALUES (:ACCT_ITEM_ID,:ITEM_SOURCE_ID,:BILL_ID,:ACCT_ITEM_TYPE_ID,:BILLING_CYCLE_ID,:ACCT_ID,:SERV_ID,:AMOUNT,SYSDATE,:FEE_CYCLE_ID,:PAYMENT_METHOD,:STATE,SYSDATE,:LATN_ID,:AI_TOTAL_ID,:ACC_NBR,:SHOULD_PAY,:FAVOUR_FEE,:TIMES,:DURATION,:MONTH_WRTOFF_FEE,:PAY_WRTOFF_FEE,:ATTR_CODE)";

void AcctItem::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void AcctItem::prepareSQL()
{
    stmt->setNumber(1,acct_item.m_acct_item_id);
    stmt->setNumber(2,acct_item.m_item_source_id);
    stmt->setNumber(3,acct_item.m_bill_id);
    stmt->setNumber(4,acct_item.m_acct_item_type_id);
    stmt->setNumber(5,acct_item.m_billing_cycle_id);
    stmt->setNumber(6,acct_item.m_acct_id);
    stmt->setNumber(7,acct_item.m_serv_id);
    stmt->setNumber(8,acct_item.m_amount);
    stmt->setNumber(9,acct_item.m_fee_cycle_id);
    stmt->setNumber(10,acct_item.m_payment_method);
    stmt->setString(11,acct_item.m_state);
    stmt->setNumber(12,acct_item.m_latn_id);
    stmt->setNumber(13,acct_item.m_ai_total_id);
    stmt->setString(14,acct_item.m_acc_nbr);
    stmt->setNumber(15,acct_item.m_should_pay);
    stmt->setNumber(16,acct_item.m_favour_fee);
    stmt->setNumber(17,acct_item.m_times);
    stmt->setNumber(18,acct_item.m_duration);
    stmt->setNumber(19,acct_item.m_month_wrtoff_fee);
    stmt->setNumber(20,acct_item.m_pay_wrtoff_fee);
    stmt->setString(21,acct_item.m_attr_code);
}

