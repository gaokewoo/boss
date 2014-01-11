#include "TransferAccount.hh"

string TransferAccount::insSQL="INSERT INTO TRANSFER_ACCOUNT(TRANSFER_ACCOUNT_ID,LOGIN_NO,OP_CODE,ID_NO,OUT_CRONTACT_NO,IN_CRONTACT_NO,PAY_TYPE,MONEY)VALUES (:TRANSFER_ACCOUNT_ID,:LOGIN_NO,:OP_CODE,:ID_NO,:OUT_CRONTACT_NO,:IN_CRONTACT_NO,:PAY_TYPE,:MONEY)";

void TransferAccount::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void TransferAccount::prepareSQL()
{
    stmt->setNumber(1,transfer_account.m_transfer_account_id);
    stmt->setString(2,transfer_account.m_login_no);
    stmt->setString(3,transfer_account.m_op_code);
    stmt->setNumber(4,transfer_account.m_id_no);
    stmt->setNumber(5,transfer_account.m_out_crontact_no);
    stmt->setNumber(6,transfer_account.m_in_crontact_no);
    stmt->setString(7,transfer_account.m_pay_type);
    stmt->setNumber(8,transfer_account.m_money);
}

