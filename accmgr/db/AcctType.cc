#include "AcctType.hh"

string AcctType::insSQL="INSERT INTO ACCT_TYPE(ACCT_TYPE,FLAG,TYPE_NAME)VALUES (:ACCT_TYPE,:FLAG,:TYPE_NAME)";

void AcctType::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void AcctType::prepareSQL()
{
    stmt->setString(1,acct_type.m_acct_type);
    stmt->setNumber(2,acct_type.m_flag);
    stmt->setString(3,acct_type.m_type_name);
}

