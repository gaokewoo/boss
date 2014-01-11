#include "AcctItemSource.hh"

string AcctItemSource::insSQL="INSERT INTO ACCT_ITEM_SOURCE(ITEM_SOURCE_ID,ACCT_ITEM_TYPE_ID,ITEM_SOURCE_TYPE,NAME,COMMENTS)VALUES (:ITEM_SOURCE_ID,:ACCT_ITEM_TYPE_ID,:ITEM_SOURCE_TYPE,:NAME,:COMMENTS)";

void AcctItemSource::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void AcctItemSource::prepareSQL()
{
    stmt->setNumber(1,acct_item_source.m_item_source_id);
    stmt->setNumber(2,acct_item_source.m_acct_item_type_id);
    stmt->setString(3,acct_item_source.m_item_source_type);
    stmt->setString(4,acct_item_source.m_name);
    stmt->setString(5,acct_item_source.m_comments);
}

