#include "OpenInterfaceHis.hh"

string OpenInterfaceHis::insSQL="INSERT INTO OPEN_INTERFACE_HIS(PAYMENT_ID,ACCT_ID,SERV_ID,OP_CODE,STAFF_ID,OPEN_TYPE,STATE,STATE_DATE,OP_NOTE,HIS_DATE)VALUES (:PAYMENT_ID,:ACCT_ID,:SERV_ID,:OP_CODE,:STAFF_ID,:OPEN_TYPE,:STATE,SYSDATE,:OP_NOTE,SYSDATE)";

void OpenInterfaceHis::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void OpenInterfaceHis::prepareSQL()
{
    stmt->setNumber(1,open_interface_his.m_payment_id);
    stmt->setNumber(2,open_interface_his.m_acct_id);
    stmt->setNumber(3,open_interface_his.m_serv_id);
    stmt->setString(4,open_interface_his.m_op_code);
    stmt->setNumber(5,open_interface_his.m_staff_id);
    stmt->setString(6,open_interface_his.m_open_type);
    stmt->setString(7,open_interface_his.m_state);
    stmt->setString(8,open_interface_his.m_op_note);
}

