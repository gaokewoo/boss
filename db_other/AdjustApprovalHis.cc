#include "AdjustApprovalHis.hh"

string AdjustApprovalHis::insSQL="INSERT INTO ADJUST_APPROVAL_HIS(LOGIN_ACCEPT,ACCT_ITEM_ID,ACCT_ITEM_TYPE_ID,ACC_NBR,ACCT_ID,BILL_MONTH,ADJ_FEE,STAFF_ID,SERV_ID,OP_NOTE,OP_TIME,PAYMENT_METHOD,SIGN_STATE,OP_CODE,SIGN_STAFF_ID,SIGN_TIME,INS_TIME,INS_STAFF_ID,INS_OP_CODE,INS_ACCEPT)VALUES (:LOGIN_ACCEPT,:ACCT_ITEM_ID,:ACCT_ITEM_TYPE_ID,:ACC_NBR,:ACCT_ID,:BILL_MONTH,:ADJ_FEE,:STAFF_ID,:SERV_ID,:OP_NOTE,SYSDATE,:PAYMENT_METHOD,:SIGN_STATE,:OP_CODE,:SIGN_STAFF_ID,SYSDATE,SYSDATE,:INS_STAFF_ID,:INS_OP_CODE,:INS_ACCEPT)";

void AdjustApprovalHis::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void AdjustApprovalHis::prepareSQL()
{
    stmt->setNumber(1,adjust_approval_his.m_login_accept);
    stmt->setNumber(2,adjust_approval_his.m_acct_item_id);
    stmt->setNumber(3,adjust_approval_his.m_acct_item_type_id);
    stmt->setString(4,adjust_approval_his.m_acc_nbr);
    stmt->setNumber(5,adjust_approval_his.m_acct_id);
    stmt->setNumber(6,adjust_approval_his.m_bill_month);
    stmt->setNumber(7,adjust_approval_his.m_adj_fee);
    stmt->setNumber(8,adjust_approval_his.m_staff_id);
    stmt->setNumber(9,adjust_approval_his.m_serv_id);
    stmt->setString(10,adjust_approval_his.m_op_note);
    stmt->setNumber(11,adjust_approval_his.m_payment_method);
    stmt->setString(12,adjust_approval_his.m_sign_state);
    stmt->setString(13,adjust_approval_his.m_op_code);
    stmt->setNumber(14,adjust_approval_his.m_sign_staff_id);
    stmt->setNumber(15,adjust_approval_his.m_ins_staff_id);
    stmt->setString(16,adjust_approval_his.m_ins_op_code);
    stmt->setNumber(17,adjust_approval_his.m_ins_accept);
}

