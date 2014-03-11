#include "ChnAccMsgList.hh"

string ChnAccMsgList::insSQL="INSERT INTO CHN_ACC_MSG_LIST(ORG_ID,PREPAY_TYPE,PREPAY_FEE,OP_ACCEPT,STAFF_ID,OP_TIME,OP_CODE,NOTE)VALUES (:ORG_ID,:PREPAY_TYPE,:PREPAY_FEE,:OP_ACCEPT,:STAFF_ID,SYSDATE,:OP_CODE,:NOTE)";

void ChnAccMsgList::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void ChnAccMsgList::prepareSQL()
{
    stmt->setNumber(1,chn_acc_msg_list.m_org_id);
    stmt->setString(2,chn_acc_msg_list.m_prepay_type);
    stmt->setNumber(3,chn_acc_msg_list.m_prepay_fee);
    stmt->setNumber(4,chn_acc_msg_list.m_op_accept);
    stmt->setNumber(5,chn_acc_msg_list.m_staff_id);
    stmt->setString(6,chn_acc_msg_list.m_op_code);
    stmt->setString(7,chn_acc_msg_list.m_note);
}

