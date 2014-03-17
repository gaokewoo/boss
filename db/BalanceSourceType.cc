#include "BalanceSourceType.hh"

string BalanceSourceType::insSQL="INSERT INTO BALANCE_SOURCE_TYPE(BALANCE_SOURCE_ID,BALANCE_SOURCE_DESC)VALUES (:BALANCE_SOURCE_ID,:BALANCE_SOURCE_DESC)";

string BalanceSourceType::emptySQL="DELETE FROM BALANCE_SOURCE_TYPE";

string BalanceSourceType::selectAllSQL="SELECT BALANCE_SOURCE_ID,BALANCE_SOURCE_DESC FROM BALANCE_SOURCE_TYPE";

void BalanceSourceType::insertData()
{
    type=0;
    setSQL(insSQL);
    executeUpdate();
}

void BalanceSourceType::emptyData()
{
    type=1;
    setSQL(emptySQL);
    executeUpdate();
}

vector<ST_BALANCE_SOURCE_TYPE> BalanceSourceType::loadAllData()
{
    type=2;
    setSQL(selectAllSQL);
    executeQuery();

    return v_data;
}

void BalanceSourceType::doParse()
{
    balance_source_type.m_balance_source_id = (long)rset->getNumber(1);
    balance_source_type.m_balance_source_desc = rset->getString(2);

    v_data.push_back(balance_source_type);
}

void BalanceSourceType::prepareSQL()
{
    if (type == 0)
    {
    stmt->setNumber(1,balance_source_type.m_balance_source_id);
    stmt->setString(2,balance_source_type.m_balance_source_desc);
    }
}

