#include "OweBalanceInfo.hh"

string OweBalanceInfo::insSQL="INSERT INTO OWE_BALANCE_INFO(ACCT_ID,SERV_ID,ACC_NBR,PREPAY_FEE,LIMIT_OWE,OWE_FEE,UNBILL_FEE,OP_TIME)VALUES (:ACCT_ID,:SERV_ID,:ACC_NBR,:PREPAY_FEE,:LIMIT_OWE,:OWE_FEE,:UNBILL_FEE,SYSDATE)";

void OweBalanceInfo::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void OweBalanceInfo::prepareSQL()
{
    stmt->setNumber(1,owe_balance_info.m_acct_id);
    stmt->setNumber(2,owe_balance_info.m_serv_id);
    stmt->setString(3,owe_balance_info.m_acc_nbr);
    stmt->setNumber(4,owe_balance_info.m_prepay_fee);
    stmt->setNumber(5,owe_balance_info.m_limit_owe);
    stmt->setNumber(6,owe_balance_info.m_owe_fee);
    stmt->setNumber(7,owe_balance_info.m_unbill_fee);
}

