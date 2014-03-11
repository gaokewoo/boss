#include "ZtOweTotalMid.hh"

string ZtOweTotalMid::insSQL="INSERT INTO ZT_OWE_TOTAL_MID(STAFF_ID,STAFF_ORG_ID,LOGIN_ACCEPT,ACCT_ID,ZT_METHOD,SERV_ID,CYCLE_FLAG,BILLING_CYCLE_ID,ACC_NBR,REGION_ID,ACCT_NAME,SHOULD_PAY,FAVOUR_FEE,PAYED_PREPAY,PAYED_LATER,PREPAY_FEE,AMOUNT,DELAY_RATE,DELAY_FEE,OTHER_FEE,SHOULD_FEE,PAYMENT_ID,BILL_FLAG,STATUS,STATUS_FLAG,STATUS_TIME,INSERT_TIME,RESV)VALUES (:STAFF_ID,:STAFF_ORG_ID,:LOGIN_ACCEPT,:ACCT_ID,:ZT_METHOD,:SERV_ID,:CYCLE_FLAG,:BILLING_CYCLE_ID,:ACC_NBR,:REGION_ID,:ACCT_NAME,:SHOULD_PAY,:FAVOUR_FEE,:PAYED_PREPAY,:PAYED_LATER,:PREPAY_FEE,:AMOUNT,:DELAY_RATE,:DELAY_FEE,:OTHER_FEE,:SHOULD_FEE,:PAYMENT_ID,:BILL_FLAG,:STATUS,:STATUS_FLAG,SYSDATE,SYSDATE,:RESV)";

void ZtOweTotalMid::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void ZtOweTotalMid::prepareSQL()
{
    stmt->setNumber(1,zt_owe_total_mid.m_staff_id);
    stmt->setNumber(2,zt_owe_total_mid.m_staff_org_id);
    stmt->setNumber(3,zt_owe_total_mid.m_login_accept);
    stmt->setNumber(4,zt_owe_total_mid.m_acct_id);
    stmt->setString(5,zt_owe_total_mid.m_zt_method);
    stmt->setNumber(6,zt_owe_total_mid.m_serv_id);
    stmt->setString(7,zt_owe_total_mid.m_cycle_flag);
    stmt->setNumber(8,zt_owe_total_mid.m_billing_cycle_id);
    stmt->setString(9,zt_owe_total_mid.m_acc_nbr);
    stmt->setNumber(10,zt_owe_total_mid.m_region_id);
    stmt->setString(11,zt_owe_total_mid.m_acct_name);
    stmt->setNumber(12,zt_owe_total_mid.m_should_pay);
    stmt->setNumber(13,zt_owe_total_mid.m_favour_fee);
    stmt->setNumber(14,zt_owe_total_mid.m_payed_prepay);
    stmt->setNumber(15,zt_owe_total_mid.m_payed_later);
    stmt->setNumber(16,zt_owe_total_mid.m_prepay_fee);
    stmt->setNumber(17,zt_owe_total_mid.m_amount);
    stmt->setNumber(18,zt_owe_total_mid.m_delay_rate);
    stmt->setNumber(19,zt_owe_total_mid.m_delay_fee);
    stmt->setNumber(20,zt_owe_total_mid.m_other_fee);
    stmt->setNumber(21,zt_owe_total_mid.m_should_fee);
    stmt->setNumber(22,zt_owe_total_mid.m_payment_id);
    stmt->setString(23,zt_owe_total_mid.m_bill_flag);
    stmt->setString(24,zt_owe_total_mid.m_status);
    stmt->setString(25,zt_owe_total_mid.m_status_flag);
    stmt->setString(26,zt_owe_total_mid.m_resv);
}

