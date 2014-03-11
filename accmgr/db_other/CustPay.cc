#include "CustPay.hh"

string CustPay::insSQL="INSERT INTO CUST_PAY(LOGIN_ACCEPT,CUST_ID,CUST_LOCATION,CUST_NAME,STATE,EFF_DATE,CUST_TYPE,CERTIFICATE_TYPE,CERTIFICATE_NO,CONTACT_ADDR,CUST_VALUE,PAY_MONEY,OP_TIME,PRINT_NUM,ACC_NBR)VALUES (:LOGIN_ACCEPT,:CUST_ID,:CUST_LOCATION,:CUST_NAME,:STATE,SYSDATE,:CUST_TYPE,:CERTIFICATE_TYPE,:CERTIFICATE_NO,:CONTACT_ADDR,:CUST_VALUE,:PAY_MONEY,SYSDATE,:PRINT_NUM,:ACC_NBR)";

void CustPay::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void CustPay::prepareSQL()
{
    stmt->setNumber(1,cust_pay.m_login_accept);
    stmt->setNumber(2,cust_pay.m_cust_id);
    stmt->setNumber(3,cust_pay.m_cust_location);
    stmt->setString(4,cust_pay.m_cust_name);
    stmt->setString(5,cust_pay.m_state);
    stmt->setString(6,cust_pay.m_cust_type);
    stmt->setString(7,cust_pay.m_certificate_type);
    stmt->setString(8,cust_pay.m_certificate_no);
    stmt->setString(9,cust_pay.m_contact_addr);
    stmt->setNumber(10,cust_pay.m_cust_value);
    stmt->setNumber(11,cust_pay.m_pay_money);
    stmt->setNumber(12,cust_pay.m_print_num);
    stmt->setString(13,cust_pay.m_acc_nbr);
}

