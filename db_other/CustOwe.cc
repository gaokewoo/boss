#include "CustOwe.hh"

string CustOwe::insSQL="INSERT INTO CUST_OWE(LOGIN_ACCEPT,CUST_ID,ACCT_ID,SERV_ID,BILLING_CYCLE_ID,AMOUNT,DELAY_FEE,ACC_NBR,STAFF_ID,OP_TIME)VALUES (:LOGIN_ACCEPT,:CUST_ID,:ACCT_ID,:SERV_ID,:BILLING_CYCLE_ID,:AMOUNT,:DELAY_FEE,:ACC_NBR,:STAFF_ID,SYSDATE)";

void CustOwe::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void CustOwe::prepareSQL()
{
    stmt->setNumber(1,cust_owe.m_login_accept);
    stmt->setNumber(2,cust_owe.m_cust_id);
    stmt->setNumber(3,cust_owe.m_acct_id);
    stmt->setNumber(4,cust_owe.m_serv_id);
    stmt->setNumber(5,cust_owe.m_billing_cycle_id);
    stmt->setNumber(6,cust_owe.m_amount);
    stmt->setNumber(7,cust_owe.m_delay_fee);
    stmt->setString(8,cust_owe.m_acc_nbr);
    stmt->setNumber(9,cust_owe.m_staff_id);
}

