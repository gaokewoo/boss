#include "DepositOpr.hh"

string DepositOpr::insSQL="INSERT INTO DEPOSIT_OPR(DEPOSIT_OPR_SN,ACCT_ID,SERV_ID,DEPOSIT_TYPE,DEPOSIT_FEE,OP_CODE,STAFF_ID,OP_TIME,NOTE)VALUES (:DEPOSIT_OPR_SN,:ACCT_ID,:SERV_ID,:DEPOSIT_TYPE,:DEPOSIT_FEE,:OP_CODE,:STAFF_ID,SYSDATE,:NOTE)";

void DepositOpr::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void DepositOpr::prepareSQL()
{
    stmt->setNumber(1,deposit_opr.m_deposit_opr_sn);
    stmt->setNumber(2,deposit_opr.m_acct_id);
    stmt->setNumber(3,deposit_opr.m_serv_id);
    stmt->setString(4,deposit_opr.m_deposit_type);
    stmt->setNumber(5,deposit_opr.m_deposit_fee);
    stmt->setString(6,deposit_opr.m_op_code);
    stmt->setNumber(7,deposit_opr.m_staff_id);
    stmt->setString(8,deposit_opr.m_note);
}

