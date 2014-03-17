#include "OweBusinessInterfaceHis.hh"

string OweBusinessInterfaceHis::insSQL="INSERT INTO OWE_BUSINESS_INTERFACE_HIS(SERV_ID,ACC_NBR,ACCT_ID,DELAY_TIME,STAFF_ID,OP_CODE,OP_TIME,REASON_DESC,STATE,STATE_DATE)VALUES (:SERV_ID,:ACC_NBR,:ACCT_ID,SYSDATE,:STAFF_ID,:OP_CODE,SYSDATE,:REASON_DESC,:STATE,SYSDATE)";

void OweBusinessInterfaceHis::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void OweBusinessInterfaceHis::prepareSQL()
{
    stmt->setNumber(1,owe_business_interface_his.m_serv_id);
    stmt->setString(2,owe_business_interface_his.m_acc_nbr);
    stmt->setNumber(3,owe_business_interface_his.m_acct_id);
    stmt->setNumber(4,owe_business_interface_his.m_staff_id);
    stmt->setString(5,owe_business_interface_his.m_op_code);
    stmt->setString(6,owe_business_interface_his.m_reason_desc);
    stmt->setString(7,owe_business_interface_his.m_state);
}

