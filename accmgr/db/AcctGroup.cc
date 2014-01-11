#include "AcctGroup.hh"

string AcctGroup::insSQL="INSERT INTO ACCT_GROUP(ACCT_GROUP_ID,ACCT_GROUP_DESC)VALUES (:ACCT_GROUP_ID,:ACCT_GROUP_DESC)";

void AcctGroup::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void AcctGroup::prepareSQL()
{
    stmt->setNumber(1,acct_group.m_acct_group_id);
    stmt->setString(2,acct_group.m_acct_group_desc);
}

