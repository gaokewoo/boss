#include "PayInterface.hh"

string PayInterface::insSQL="INSERT INTO PAY_INTERFACE(LOGIN_ACCEPT,ACCT_ID,SERV_ID,ACC_NBR,PAYMENT_METHOD,PAY_MONEY,PAY_NOTE,STAFF_ID,INSERT_DATE)VALUES (:LOGIN_ACCEPT,:ACCT_ID,:SERV_ID,:ACC_NBR,:PAYMENT_METHOD,:PAY_MONEY,:PAY_NOTE,:STAFF_ID,SYSDATE)";

void PayInterface::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void PayInterface::prepareSQL()
{
    stmt->setNumber(1,pay_interface.m_login_accept);
    stmt->setNumber(2,pay_interface.m_acct_id);
    stmt->setNumber(3,pay_interface.m_serv_id);
    stmt->setString(4,pay_interface.m_acc_nbr);
    stmt->setNumber(5,pay_interface.m_payment_method);
    stmt->setNumber(6,pay_interface.m_pay_money);
    stmt->setString(7,pay_interface.m_pay_note);
    stmt->setNumber(8,pay_interface.m_staff_id);
}

