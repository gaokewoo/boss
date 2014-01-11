#include "OweStopInterface.hh"

string OweStopInterface::insSQL="INSERT INTO OWE_STOP_INTERFACE(SERV_ID,ACTION_TYPE_ID,NEW_STATUS,REASON_ID,STAFF_CODE,CUST_ORDER_ORIGIN,CREATE_DATE,CREATE_ACCEPT,DEAL_STATUS,FUNCTION_CODE,OP_NOTE)VALUES (:SERV_ID,:ACTION_TYPE_ID,:NEW_STATUS,:REASON_ID,:STAFF_CODE,:CUST_ORDER_ORIGIN,SYSDATE,:CREATE_ACCEPT,:DEAL_STATUS,:FUNCTION_CODE,:OP_NOTE)";

void OweStopInterface::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void OweStopInterface::prepareSQL()
{
    stmt->setNumber(1,owe_stop_interface.m_serv_id);
    stmt->setNumber(2,owe_stop_interface.m_action_type_id);
    stmt->setString(3,owe_stop_interface.m_new_status);
    stmt->setString(4,owe_stop_interface.m_reason_id);
    stmt->setString(5,owe_stop_interface.m_staff_code);
    stmt->setNumber(6,owe_stop_interface.m_cust_order_origin);
    stmt->setNumber(7,owe_stop_interface.m_create_accept);
    stmt->setNumber(8,owe_stop_interface.m_deal_status);
    stmt->setString(9,owe_stop_interface.m_function_code);
    stmt->setString(10,owe_stop_interface.m_op_note);
}

