#include "BusiOrderInterface.hh"

string BusiOrderInterface::insSQL="INSERT INTO BUSI_ORDER_INTERFACE(ORDER_ACCEPT,SERV_ORDER_ID,LOGIN_NO,OP_CODE,INSERT_TIME,ID_NO,CONTRACT_NO,DEAL_FLAG,DEAL_TIME)VALUES (:ORDER_ACCEPT,:SERV_ORDER_ID,:LOGIN_NO,:OP_CODE,SYSDATE,:ID_NO,:CONTRACT_NO,:DEAL_FLAG,SYSDATE)";

void BusiOrderInterface::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void BusiOrderInterface::prepareSQL()
{
    stmt->setNumber(1,busi_order_interface.m_order_accept);
    stmt->setString(2,busi_order_interface.m_serv_order_id);
    stmt->setString(3,busi_order_interface.m_login_no);
    stmt->setString(4,busi_order_interface.m_op_code);
    stmt->setNumber(5,busi_order_interface.m_id_no);
    stmt->setNumber(6,busi_order_interface.m_contract_no);
    stmt->setString(7,busi_order_interface.m_deal_flag);
}

