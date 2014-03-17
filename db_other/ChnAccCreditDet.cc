#include "ChnAccCreditDet.hh"

string ChnAccCreditDet::insSQL="INSERT INTO CHN_ACC_CREDIT_DET(ORG_ID,CREDIT_CODE,CREDIT_VALUE,USED_CREDIT,OP_ACCEPT,STAFF_ID,OP_TIME,OP_CODE,NOTE)VALUES (:ORG_ID,:CREDIT_CODE,:CREDIT_VALUE,:USED_CREDIT,:OP_ACCEPT,:STAFF_ID,SYSDATE,:OP_CODE,:NOTE)";

void ChnAccCreditDet::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void ChnAccCreditDet::prepareSQL()
{
    stmt->setNumber(1,chn_acc_credit_det.m_org_id);
    stmt->setString(2,chn_acc_credit_det.m_credit_code);
    stmt->setNumber(3,chn_acc_credit_det.m_credit_value);
    stmt->setNumber(4,chn_acc_credit_det.m_used_credit);
    stmt->setNumber(5,chn_acc_credit_det.m_op_accept);
    stmt->setNumber(6,chn_acc_credit_det.m_staff_id);
    stmt->setString(7,chn_acc_credit_det.m_op_code);
    stmt->setString(8,chn_acc_credit_det.m_note);
}

