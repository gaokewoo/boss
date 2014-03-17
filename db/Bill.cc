#include "Bill.hh"

string Bill::insSQL="INSERT INTO BILL(BILL_ID,AI_TOTAL_ID,PAYMENT_ID,PAYMENT_METHOD,BILLING_CYCLE_ID,PARTY_ROLE_ID,ACCT_ID,SERV_ID,ACC_NBR,BILL_AMOUNT,LATE_FEE,DERATE_LATE_FEE,BALANCE,LAST_CHANGE,CUR_CHANGE,CREATED_DATE,PAYMENT_DATE,USE_DERATE_BLANCE,INVOICE_ID,STATE,STATE_DATE)VALUES (:BILL_ID,:AI_TOTAL_ID,:PAYMENT_ID,:PAYMENT_METHOD,:BILLING_CYCLE_ID,:PARTY_ROLE_ID,:ACCT_ID,:SERV_ID,:ACC_NBR,:BILL_AMOUNT,:LATE_FEE,:DERATE_LATE_FEE,:BALANCE,:LAST_CHANGE,:CUR_CHANGE,SYSDATE,SYSDATE,:USE_DERATE_BLANCE,:INVOICE_ID,:STATE,SYSDATE)";

void Bill::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void Bill::prepareSQL()
{
    stmt->setNumber(1,bill.m_bill_id);
    stmt->setNumber(2,bill.m_ai_total_id);
    stmt->setNumber(3,bill.m_payment_id);
    stmt->setNumber(4,bill.m_payment_method);
    stmt->setNumber(5,bill.m_billing_cycle_id);
    stmt->setNumber(6,bill.m_party_role_id);
    stmt->setNumber(7,bill.m_acct_id);
    stmt->setNumber(8,bill.m_serv_id);
    stmt->setString(9,bill.m_acc_nbr);
    stmt->setNumber(10,bill.m_bill_amount);
    stmt->setNumber(11,bill.m_late_fee);
    stmt->setNumber(12,bill.m_derate_late_fee);
    stmt->setNumber(13,bill.m_balance);
    stmt->setNumber(14,bill.m_last_change);
    stmt->setNumber(15,bill.m_cur_change);
    stmt->setNumber(16,bill.m_use_derate_blance);
    stmt->setNumber(17,bill.m_invoice_id);
    stmt->setString(18,bill.m_state);
}

