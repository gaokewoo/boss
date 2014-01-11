#include "OweItemInfo.hh"

string OweItemInfo::insSQL="INSERT INTO OWE_ITEM_INFO(ACCT_ITEM_ID,ITEM_SOURCE_ID,BILL_ID,ACCT_ITEM_TYPE_ID,BILLING_CYCLE_ID,ACCT_ID,SERV_ID,AMOUNT,CREATED_DATE,FEE_CYCLE_ID,PAYMENT_METHOD,STATE,STATE_DATE,LATN_ID,AI_TOTAL_ID,ACC_NBR,SHOULD_PAY,FAVOUR_FEE,TIMES,DURATION,MONTH_WRTOFF_FEE,PAY_WRTOFF_FEE,ATTR_CODE)VALUES (:ACCT_ITEM_ID,:ITEM_SOURCE_ID,:BILL_ID,:ACCT_ITEM_TYPE_ID,:BILLING_CYCLE_ID,:ACCT_ID,:SERV_ID,:AMOUNT,SYSDATE,:FEE_CYCLE_ID,:PAYMENT_METHOD,:STATE,SYSDATE,:LATN_ID,:AI_TOTAL_ID,:ACC_NBR,:SHOULD_PAY,:FAVOUR_FEE,:TIMES,:DURATION,:MONTH_WRTOFF_FEE,:PAY_WRTOFF_FEE,:ATTR_CODE)";

void OweItemInfo::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void OweItemInfo::prepareSQL()
{
    stmt->setNumber(1,owe_item_info.m_acct_item_id);
    stmt->setNumber(2,owe_item_info.m_item_source_id);
    stmt->setNumber(3,owe_item_info.m_bill_id);
    stmt->setNumber(4,owe_item_info.m_acct_item_type_id);
    stmt->setNumber(5,owe_item_info.m_billing_cycle_id);
    stmt->setNumber(6,owe_item_info.m_acct_id);
    stmt->setNumber(7,owe_item_info.m_serv_id);
    stmt->setNumber(8,owe_item_info.m_amount);
    stmt->setNumber(9,owe_item_info.m_fee_cycle_id);
    stmt->setNumber(10,owe_item_info.m_payment_method);
    stmt->setString(11,owe_item_info.m_state);
    stmt->setNumber(12,owe_item_info.m_latn_id);
    stmt->setNumber(13,owe_item_info.m_ai_total_id);
    stmt->setString(14,owe_item_info.m_acc_nbr);
    stmt->setNumber(15,owe_item_info.m_should_pay);
    stmt->setNumber(16,owe_item_info.m_favour_fee);
    stmt->setNumber(17,owe_item_info.m_times);
    stmt->setNumber(18,owe_item_info.m_duration);
    stmt->setNumber(19,owe_item_info.m_month_wrtoff_fee);
    stmt->setNumber(20,owe_item_info.m_pay_wrtoff_fee);
    stmt->setString(21,owe_item_info.m_attr_code);
}

