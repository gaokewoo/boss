#include "DepositFee.hh"

string DepositFee::insSQL="INSERT INTO DEPOSIT_FEE(ACCT_ID,SERV_ID,DEPOSIT_TYPE,DEPOSIT_FEE,VALID_BEGIN,VALID_END,UNPAY_BEGIN,UNPAY_END,LAST_DEPOSIT,ADD_DEPOSIT)VALUES (:ACCT_ID,:SERV_ID,:DEPOSIT_TYPE,:DEPOSIT_FEE,SYSDATE,SYSDATE,SYSDATE,SYSDATE,:LAST_DEPOSIT,:ADD_DEPOSIT)";

void DepositFee::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void DepositFee::prepareSQL()
{
    stmt->setNumber(1,deposit_fee.m_acct_id);
    stmt->setNumber(2,deposit_fee.m_serv_id);
    stmt->setString(3,deposit_fee.m_deposit_type);
    stmt->setNumber(4,deposit_fee.m_deposit_fee);
    stmt->setNumber(5,deposit_fee.m_last_deposit);
    stmt->setNumber(6,deposit_fee.m_add_deposit);
}

