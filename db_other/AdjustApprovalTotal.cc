#include "AdjustApprovalTotal.hh"

string AdjustApprovalTotal::insSQL="INSERT INTO ADJUST_APPROVAL_TOTAL(LOGIN_ACCEPT,STAFF_ID,OP_TIME,ADJ_FEE,STATE,OP_REASON,OP_NOTE,OP_CODE)VALUES (:LOGIN_ACCEPT,:STAFF_ID,SYSDATE,:ADJ_FEE,:STATE,:OP_REASON,:OP_NOTE,:OP_CODE)";

void AdjustApprovalTotal::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void AdjustApprovalTotal::prepareSQL()
{
    stmt->setNumber(1,adjust_approval_total.m_login_accept);
    stmt->setNumber(2,adjust_approval_total.m_staff_id);
    stmt->setNumber(3,adjust_approval_total.m_adj_fee);
    stmt->setString(4,adjust_approval_total.m_state);
    stmt->setString(5,adjust_approval_total.m_op_reason);
    stmt->setString(6,adjust_approval_total.m_op_note);
    stmt->setString(7,adjust_approval_total.m_op_code);
}

