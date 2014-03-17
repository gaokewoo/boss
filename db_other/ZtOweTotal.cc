#include "ZtOweTotal.hh"

string ZtOweTotal::insSQL="INSERT INTO ZT_OWE_TOTAL(LOGIN_ACCEPT,ACCT_ID,ZT_METHOD,SERV_ID,CYCLE_FLAG,BILLING_CYCLE_ID,ACC_NBR,REGION_ID,ACCT_NAME,SHOULD_PAY,FAVOUR_FEE,PAYED_PREPAY,PAYED_LATER,PREPAY_FEE,AMOUNT,DELAY_RATE,DELAY_FEE,OTHER_FEE,SHOULD_FEE,PAYMENT_ID,BILL_FLAG,STATUS,STATUS_FLAG,STATUS_TIME,INSERT_TIME,RESV)VALUES (:LOGIN_ACCEPT,:ACCT_ID,:ZT_METHOD,:SERV_ID,:CYCLE_FLAG,:BILLING_CYCLE_ID,:ACC_NBR,:REGION_ID,:ACCT_NAME,:SHOULD_PAY,:FAVOUR_FEE,:PAYED_PREPAY,:PAYED_LATER,:PREPAY_FEE,:AMOUNT,:DELAY_RATE,:DELAY_FEE,:OTHER_FEE,:SHOULD_FEE,:PAYMENT_ID,:BILL_FLAG,:STATUS,:STATUS_FLAG,SYSDATE,SYSDATE,:RESV)";

void ZtOweTotal::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void ZtOweTotal::prepareSQL()
{
    stmt->setNumber(1,zt_owe_total.m_login_accept);
    stmt->setNumber(2,zt_owe_total.m_acct_id);
    stmt->setString(3,zt_owe_total.m_zt_method);
    stmt->setNumber(4,zt_owe_total.m_serv_id);
    stmt->setString(5,zt_owe_total.m_cycle_flag);
    stmt->setNumber(6,zt_owe_total.m_billing_cycle_id);
    stmt->setString(7,zt_owe_total.m_acc_nbr);
    stmt->setNumber(8,zt_owe_total.m_region_id);
    stmt->setString(9,zt_owe_total.m_acct_name);
    stmt->setNumber(10,zt_owe_total.m_should_pay);
    stmt->setNumber(11,zt_owe_total.m_favour_fee);
    stmt->setNumber(12,zt_owe_total.m_payed_prepay);
    stmt->setNumber(13,zt_owe_total.m_payed_later);
    stmt->setNumber(14,zt_owe_total.m_prepay_fee);
    stmt->setNumber(15,zt_owe_total.m_amount);
    stmt->setNumber(16,zt_owe_total.m_delay_rate);
    stmt->setNumber(17,zt_owe_total.m_delay_fee);
    stmt->setNumber(18,zt_owe_total.m_other_fee);
    stmt->setNumber(19,zt_owe_total.m_should_fee);
    stmt->setNumber(20,zt_owe_total.m_payment_id);
    stmt->setString(21,zt_owe_total.m_bill_flag);
    stmt->setString(22,zt_owe_total.m_status);
    stmt->setString(23,zt_owe_total.m_status_flag);
    stmt->setString(24,zt_owe_total.m_resv);
}

