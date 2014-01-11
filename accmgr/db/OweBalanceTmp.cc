#include "OweBalanceTmp.hh"

string OweBalanceTmp::insSQL="INSERT INTO OWE_BALANCE_TMP(ACCT_ID,SERV_ID)VALUES (:ACCT_ID,:SERV_ID)";

void OweBalanceTmp::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void OweBalanceTmp::prepareSQL()
{
    stmt->setNumber(1,owe_balance_tmp.m_acct_id);
    stmt->setNumber(2,owe_balance_tmp.m_serv_id);
}

