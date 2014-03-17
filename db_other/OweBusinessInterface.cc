#include "OweBusinessInterface.hh"

string OweBusinessInterface::insSQL="INSERT INTO OWE_BUSINESS_INTERFACE(SERV_ID,ACC_NBR,ACCT_ID,DELAY_TIME,STAFF_ID,OP_CODE,OP_TIME,REASON_DESC,STATE,STATE_DATE)VALUES (:SERV_ID,:ACC_NBR,:ACCT_ID,SYSDATE,:STAFF_ID,:OP_CODE,SYSDATE,:REASON_DESC,:STATE,SYSDATE)";

void OweBusinessInterface::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void OweBusinessInterface::prepareSQL()
{
    stmt->setNumber(1,owe_business_interface.m_serv_id);
    stmt->setString(2,owe_business_interface.m_acc_nbr);
    stmt->setNumber(3,owe_business_interface.m_acct_id);
    stmt->setNumber(4,owe_business_interface.m_staff_id);
    stmt->setString(5,owe_business_interface.m_op_code);
    stmt->setString(6,owe_business_interface.m_reason_desc);
    stmt->setString(7,owe_business_interface.m_state);
}

