#include "AcctItemGroupMember.hh"

string AcctItemGroupMember::insSQL="INSERT INTO ACCT_ITEM_GROUP_MEMBER(ITEM_SOURCE_ID,ACCT_ITEM_TYPE_ID,ACCT_ITEM_GROUP_ID,STATE,STATE_DATE)VALUES (:ITEM_SOURCE_ID,:ACCT_ITEM_TYPE_ID,:ACCT_ITEM_GROUP_ID,:STATE,SYSDATE)";

void AcctItemGroupMember::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void AcctItemGroupMember::prepareSQL()
{
    stmt->setNumber(1,acct_item_group_member.m_item_source_id);
    stmt->setNumber(2,acct_item_group_member.m_acct_item_type_id);
    stmt->setNumber(3,acct_item_group_member.m_acct_item_group_id);
    stmt->setString(4,acct_item_group_member.m_state);
}

