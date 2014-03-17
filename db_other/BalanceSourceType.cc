#include "BalanceSourceType.hh"

string BalanceSourceType::insSQL="INSERT INTO BALANCE_SOURCE_TYPE(BALANCE_SOURCE_ID,BALANCE_SOURCE_DESC)VALUES (:BALANCE_SOURCE_ID,:BALANCE_SOURCE_DESC)";

void BalanceSourceType::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void BalanceSourceType::prepareSQL()
{
    stmt->setNumber(1,balance_source_type.m_balance_source_id);
    stmt->setString(2,balance_source_type.m_balance_source_desc);
}

