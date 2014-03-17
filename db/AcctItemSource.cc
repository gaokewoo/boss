#include "AcctItemSource.hh"

string AcctItemSource::insSQL="INSERT INTO ACCT_ITEM_SOURCE(ITEM_SOURCE_ID,ACCT_ITEM_TYPE_ID,ITEM_SOURCE_TYPE,NAME,COMMENTS)VALUES (:ITEM_SOURCE_ID,:ACCT_ITEM_TYPE_ID,:ITEM_SOURCE_TYPE,:NAME,:COMMENTS)";

string AcctItemSource::emptySQL="DELETE FROM ACCT_ITEM_SOURCE";

string AcctItemSource::selectAllSQL="SELECT ITEM_SOURCE_ID,ACCT_ITEM_TYPE_ID,ITEM_SOURCE_TYPE,NAME,COMMENTS FROM ACCT_ITEM_SOURCE";

void AcctItemSource::insertData()
{
    type=0;
    setSQL(insSQL);
    executeUpdate();
}

void AcctItemSource::emptyData()
{
    type=1;
    setSQL(emptySQL);
    executeUpdate();
}

vector<ST_ACCT_ITEM_SOURCE> AcctItemSource::loadAllData()
{
    type=2;
    setSQL(selectAllSQL);
    executeQuery();

    return v_data;
}

void AcctItemSource::doParse()
{
    acct_item_source.m_item_source_id = (long)rset->getNumber(1);
    acct_item_source.m_acct_item_type_id = (long)rset->getNumber(2);
    acct_item_source.m_item_source_type = rset->getString(3);
    acct_item_source.m_name = rset->getString(4);
    acct_item_source.m_comments = rset->getString(5);

    v_data.push_back(acct_item_source);
}

void AcctItemSource::prepareSQL()
{
    if (type == 0)
    {
    stmt->setNumber(1,acct_item_source.m_item_source_id);
    stmt->setNumber(2,acct_item_source.m_acct_item_type_id);
    stmt->setString(3,acct_item_source.m_item_source_type);
    stmt->setString(4,acct_item_source.m_name);
    stmt->setString(5,acct_item_source.m_comments);
    }
}

