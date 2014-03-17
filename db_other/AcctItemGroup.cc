#include "AcctItemGroup.hh"

string AcctItemGroup::insSQL="INSERT INTO ACCT_ITEM_GROUP(ACCT_ITEM_GROUP_ID,ACCT_ITEM_GROUP_NAME,PRIORITY,STATE,STATE_DATE,ACCT_ITEM_GROUP_TYPE)VALUES (:ACCT_ITEM_GROUP_ID,:ACCT_ITEM_GROUP_NAME,:PRIORITY,:STATE,SYSDATE,:ACCT_ITEM_GROUP_TYPE)";

void AcctItemGroup::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void AcctItemGroup::prepareSQL()
{
    stmt->setNumber(1,acct_item_group.m_acct_item_group_id);
    stmt->setString(2,acct_item_group.m_acct_item_group_name);
    stmt->setNumber(3,acct_item_group.m_priority);
    stmt->setString(4,acct_item_group.m_state);
    stmt->setString(5,acct_item_group.m_acct_item_group_type);
}

