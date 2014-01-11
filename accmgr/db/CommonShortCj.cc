#include "CommonShortCj.hh"

string CommonShortCj::insSQL="INSERT INTO COMMON_SHORT_CJ(COMMAND_ID,LOGIN_ACCEPT,MSG_LEVEL,ACC_NBR,MSG,ORDER_CODE,BACK_CODE,DX_OP_CODE,STAFF_CODE,OP_TIME)VALUES (:COMMAND_ID,:LOGIN_ACCEPT,:MSG_LEVEL,:ACC_NBR,:MSG,:ORDER_CODE,:BACK_CODE,:DX_OP_CODE,:STAFF_CODE,SYSDATE)";

void CommonShortCj::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void CommonShortCj::prepareSQL()
{
    stmt->setNumber(1,common_short_cj.m_command_id);
    stmt->setNumber(2,common_short_cj.m_login_accept);
    stmt->setNumber(3,common_short_cj.m_msg_level);
    stmt->setString(4,common_short_cj.m_acc_nbr);
    stmt->setString(5,common_short_cj.m_msg);
    stmt->setNumber(6,common_short_cj.m_order_code);
    stmt->setNumber(7,common_short_cj.m_back_code);
    stmt->setString(8,common_short_cj.m_dx_op_code);
    stmt->setString(9,common_short_cj.m_staff_code);
}

