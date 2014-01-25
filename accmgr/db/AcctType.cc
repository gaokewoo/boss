#include "AcctType.hh"

string AcctType::insSQL="INSERT INTO ACCT_TYPE(ACCT_TYPE,FLAG,TYPE_NAME)VALUES (:ACCT_TYPE,:FLAG,:TYPE_NAME)";

string AcctType::emptySQL="DELETE FROM ACCT_TYPE";

string AcctType::selectAllSQL="SELECT ACCT_TYPE,FLAG,TYPE_NAME FROM ACCT_TYPE";

void AcctType::insertData()
{
    type=0;
    setSQL(insSQL);
    executeUpdate();
}

void AcctType::emptyData()
{
    type=1;
    setSQL(emptySQL);
    executeUpdate();
}

vector<ST_ACCT_TYPE> AcctType::loadAllData()
{
    type=2;
    setSQL(selectAllSQL);
    executeQuery();

    return v_data;
}

void AcctType::doParse()
{
    acct_type.m_acct_type = rset->getString(1);
    acct_type.m_flag = (long)rset->getNumber(2);
    acct_type.m_type_name = rset->getString(3);

    v_data.push_back(acct_type);
}

void AcctType::prepareSQL()
{
    if (type == 0)
    {
    stmt->setString(1,acct_type.m_acct_type);
    stmt->setNumber(2,acct_type.m_flag);
    stmt->setString(3,acct_type.m_type_name);
    }
}

