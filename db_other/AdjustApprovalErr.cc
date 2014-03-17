#include "AdjustApprovalErr.hh"

string AdjustApprovalErr::insSQL="INSERT INTO ADJUST_APPROVAL_ERR(ACC_NBR,ACCT_ID,BILL_MONTH,ACCT_ITEM_TYPE_ID,ADJ_FEE,STAFF_ID,SERV_ID,RETURN_CODE,OP_NOTE,OP_TIME,SIGN_TIME,PAYMENT_METHOD)VALUES (:ACC_NBR,:ACCT_ID,:BILL_MONTH,:ACCT_ITEM_TYPE_ID,:ADJ_FEE,:STAFF_ID,:SERV_ID,:RETURN_CODE,:OP_NOTE,SYSDATE,SYSDATE,:PAYMENT_METHOD)";

void AdjustApprovalErr::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void AdjustApprovalErr::prepareSQL()
{
    stmt->setString(1,adjust_approval_err.m_acc_nbr);
    stmt->setNumber(2,adjust_approval_err.m_acct_id);
    stmt->setNumber(3,adjust_approval_err.m_bill_month);
    stmt->setNumber(4,adjust_approval_err.m_acct_item_type_id);
    stmt->setNumber(5,adjust_approval_err.m_adj_fee);
    stmt->setNumber(6,adjust_approval_err.m_staff_id);
    stmt->setNumber(7,adjust_approval_err.m_serv_id);
    stmt->setNumber(8,adjust_approval_err.m_return_code);
    stmt->setString(9,adjust_approval_err.m_op_note);
    stmt->setNumber(10,adjust_approval_err.m_payment_method);
}

