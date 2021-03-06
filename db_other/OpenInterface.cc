#include "OpenInterface.hh"

string OpenInterface::insSQL="INSERT INTO OPEN_INTERFACE(PAYMENT_ID,ACCT_ID,SERV_ID,OP_CODE,STAFF_ID,OPEN_TYPE,STATE,STATE_DATE,OP_NOTE)VALUES (:PAYMENT_ID,:ACCT_ID,:SERV_ID,:OP_CODE,:STAFF_ID,:OPEN_TYPE,:STATE,SYSDATE,:OP_NOTE)";

void OpenInterface::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void OpenInterface::prepareSQL()
{
    stmt->setNumber(1,open_interface.m_payment_id);
    stmt->setNumber(2,open_interface.m_acct_id);
    stmt->setNumber(3,open_interface.m_serv_id);
    stmt->setString(4,open_interface.m_op_code);
    stmt->setNumber(5,open_interface.m_staff_id);
    stmt->setString(6,open_interface.m_open_type);
    stmt->setString(7,open_interface.m_state);
    stmt->setString(8,open_interface.m_op_note);
}

