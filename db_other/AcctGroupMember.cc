#include "AcctGroupMember.hh"

string AcctGroupMember::insSQL="INSERT INTO ACCT_GROUP_MEMBER(ACCT_GROUP_ID,ACCT_ID,ROLE)VALUES (:ACCT_GROUP_ID,:ACCT_ID,:ROLE)";

void AcctGroupMember::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void AcctGroupMember::prepareSQL()
{
    stmt->setNumber(1,acct_group_member.m_acct_group_id);
    stmt->setNumber(2,acct_group_member.m_acct_id);
    stmt->setString(3,acct_group_member.m_role);
}

