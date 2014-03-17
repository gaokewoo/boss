#include "CustOweTotal.hh"

string CustOweTotal::insSQL="INSERT INTO CUST_OWE_TOTAL(PAY_ID,LOGIN_ACCEPT,CUST_ID,ACCT_ID,SERV_ID,AMOUNT,DELAY_FEE,PREPAY_FEE,OTHER_FEE,SHOULD_FEE,BALANCE_FEE,PAY_MONEY,ACC_NBR,DEAL_FLAG,STAFF_ID,OP_TIME)VALUES (:PAY_ID,:LOGIN_ACCEPT,:CUST_ID,:ACCT_ID,:SERV_ID,:AMOUNT,:DELAY_FEE,:PREPAY_FEE,:OTHER_FEE,:SHOULD_FEE,:BALANCE_FEE,:PAY_MONEY,:ACC_NBR,:DEAL_FLAG,:STAFF_ID,SYSDATE)";

void CustOweTotal::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void CustOweTotal::prepareSQL()
{
    stmt->setNumber(1,cust_owe_total.m_pay_id);
    stmt->setNumber(2,cust_owe_total.m_login_accept);
    stmt->setNumber(3,cust_owe_total.m_cust_id);
    stmt->setNumber(4,cust_owe_total.m_acct_id);
    stmt->setNumber(5,cust_owe_total.m_serv_id);
    stmt->setNumber(6,cust_owe_total.m_amount);
    stmt->setNumber(7,cust_owe_total.m_delay_fee);
    stmt->setNumber(8,cust_owe_total.m_prepay_fee);
    stmt->setNumber(9,cust_owe_total.m_other_fee);
    stmt->setNumber(10,cust_owe_total.m_should_fee);
    stmt->setNumber(11,cust_owe_total.m_balance_fee);
    stmt->setNumber(12,cust_owe_total.m_pay_money);
    stmt->setString(13,cust_owe_total.m_acc_nbr);
    stmt->setString(14,cust_owe_total.m_deal_flag);
    stmt->setNumber(15,cust_owe_total.m_staff_id);
}

