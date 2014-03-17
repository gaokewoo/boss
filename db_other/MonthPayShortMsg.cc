#include "MonthPayShortMsg.hh"

string MonthPayShortMsg::insSQL="INSERT INTO MONTH_PAY_SHORT_MSG(COMMAND_ID,LOGIN_ACCEPT,MSG_LEVEL,ACC_NBR,MSG,ORDER_CODE,BACK_CODE,DX_OP_CODE,STAFF_CODE,OP_TIME)VALUES (:COMMAND_ID,:LOGIN_ACCEPT,:MSG_LEVEL,:ACC_NBR,:MSG,:ORDER_CODE,:BACK_CODE,:DX_OP_CODE,:STAFF_CODE,SYSDATE)";

void MonthPayShortMsg::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void MonthPayShortMsg::prepareSQL()
{
    stmt->setNumber(1,month_pay_short_msg.m_command_id);
    stmt->setNumber(2,month_pay_short_msg.m_login_accept);
    stmt->setNumber(3,month_pay_short_msg.m_msg_level);
    stmt->setString(4,month_pay_short_msg.m_acc_nbr);
    stmt->setString(5,month_pay_short_msg.m_msg);
    stmt->setNumber(6,month_pay_short_msg.m_order_code);
    stmt->setNumber(7,month_pay_short_msg.m_back_code);
    stmt->setString(8,month_pay_short_msg.m_dx_op_code);
    stmt->setString(9,month_pay_short_msg.m_staff_code);
}

