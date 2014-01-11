#include "PayInterfaceHis.hh"

string PayInterfaceHis::insSQL="INSERT INTO PAY_INTERFACE_HIS(LOGIN_ACCEPT,ACCT_ID,SERV_ID,ACC_NBR,PAYMENT_METHOD,PAY_MONEY,PAY_NOTE,STAFF_ID,INSERT_DATE,STATE,STATE_DATE,PAYMENT_ID,PAYMENT_DATE)VALUES (:LOGIN_ACCEPT,:ACCT_ID,:SERV_ID,:ACC_NBR,:PAYMENT_METHOD,:PAY_MONEY,:PAY_NOTE,:STAFF_ID,SYSDATE,:STATE,SYSDATE,:PAYMENT_ID,SYSDATE)";

void PayInterfaceHis::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void PayInterfaceHis::prepareSQL()
{
    stmt->setNumber(1,pay_interface_his.m_login_accept);
    stmt->setNumber(2,pay_interface_his.m_acct_id);
    stmt->setNumber(3,pay_interface_his.m_serv_id);
    stmt->setString(4,pay_interface_his.m_acc_nbr);
    stmt->setNumber(5,pay_interface_his.m_payment_method);
    stmt->setNumber(6,pay_interface_his.m_pay_money);
    stmt->setString(7,pay_interface_his.m_pay_note);
    stmt->setNumber(8,pay_interface_his.m_staff_id);
    stmt->setString(9,pay_interface_his.m_state);
    stmt->setNumber(10,pay_interface_his.m_payment_id);
}

