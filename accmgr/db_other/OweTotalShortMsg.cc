#include "OweTotalShortMsg.hh"

string OweTotalShortMsg::insSQL="INSERT INTO OWE_TOTAL_SHORT_MSG(COMMAND_ID,LOGIN_ACCEPT,MSG_LEVEL,ACC_NBR,MSG,ORDER_CODE,BACK_CODE,DX_OP_CODE,STAFF_CODE,OP_TIME)VALUES (:COMMAND_ID,:LOGIN_ACCEPT,:MSG_LEVEL,:ACC_NBR,:MSG,:ORDER_CODE,:BACK_CODE,:DX_OP_CODE,:STAFF_CODE,SYSDATE)";

void OweTotalShortMsg::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void OweTotalShortMsg::prepareSQL()
{
    stmt->setNumber(1,owe_total_short_msg.m_command_id);
    stmt->setNumber(2,owe_total_short_msg.m_login_accept);
    stmt->setNumber(3,owe_total_short_msg.m_msg_level);
    stmt->setString(4,owe_total_short_msg.m_acc_nbr);
    stmt->setString(5,owe_total_short_msg.m_msg);
    stmt->setNumber(6,owe_total_short_msg.m_order_code);
    stmt->setNumber(7,owe_total_short_msg.m_back_code);
    stmt->setString(8,owe_total_short_msg.m_dx_op_code);
    stmt->setString(9,owe_total_short_msg.m_staff_code);
}

