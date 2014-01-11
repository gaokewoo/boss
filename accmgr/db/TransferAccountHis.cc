#include "TransferAccountHis.hh"

string TransferAccountHis::insSQL="INSERT INTO TRANSFER_ACCOUNT_HIS(TRANSFER_ACCOUNT_ID,LOGIN_NO,OP_CODE,ID_NO,OUT_CRONTACT_NO,IN_CRONTACT_NO,PAY_TYPE,MONEY,DEAL_TIME,DEAL_RESULT)VALUES (:TRANSFER_ACCOUNT_ID,:LOGIN_NO,:OP_CODE,:ID_NO,:OUT_CRONTACT_NO,:IN_CRONTACT_NO,:PAY_TYPE,:MONEY,SYSDATE,:DEAL_RESULT)";

void TransferAccountHis::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void TransferAccountHis::prepareSQL()
{
    stmt->setNumber(1,transfer_account_his.m_transfer_account_id);
    stmt->setString(2,transfer_account_his.m_login_no);
    stmt->setString(3,transfer_account_his.m_op_code);
    stmt->setNumber(4,transfer_account_his.m_id_no);
    stmt->setNumber(5,transfer_account_his.m_out_crontact_no);
    stmt->setNumber(6,transfer_account_his.m_in_crontact_no);
    stmt->setString(7,transfer_account_his.m_pay_type);
    stmt->setNumber(8,transfer_account_his.m_money);
    stmt->setString(9,transfer_account_his.m_deal_result);
}

