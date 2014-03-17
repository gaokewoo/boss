#include "AcctItemGroup.hh"

string AcctItemGroup::insSQL="INSERT INTO ACCT_ITEM_GROUP(ACCT_ITEM_GROUP_ID,ACCT_ITEM_GROUP_NAME,PRIORITY,STATE,STATE_DATE,ACCT_ITEM_GROUP_TYPE)VALUES (:ACCT_ITEM_GROUP_ID,:ACCT_ITEM_GROUP_NAME,:PRIORITY,:STATE,SYSDATE,:ACCT_ITEM_GROUP_TYPE)";

string AcctItemGroup::emptySQL="DELETE FROM ACCT_ITEM_GROUP";

string AcctItemGroup::selectAllSQL="SELECT ACCT_ITEM_GROUP_ID,ACCT_ITEM_GROUP_NAME,PRIORITY,STATE,TO_CHAR(STATE_DATE,'YYYYMMDDHH24MISS'),ACCT_ITEM_GROUP_TYPE FROM ACCT_ITEM_GROUP";

void AcctItemGroup::insertData()
{
    type=0;
    setSQL(insSQL);
    executeUpdate();
}

void AcctItemGroup::emptyData()
{
    type=1;
    setSQL(emptySQL);
    executeUpdate();
}

vector<ST_ACCT_ITEM_GROUP> AcctItemGroup::loadAllData()
{
    type=2;
    setSQL(selectAllSQL);
    executeQuery();

    return v_data;
}

void AcctItemGroup::doParse()
{
    acct_item_group.m_acct_item_group_id = (long)rset->getNumber(1);
    acct_item_group.m_acct_item_group_name = rset->getString(2);
    acct_item_group.m_priority = (long)rset->getNumber(3);
    acct_item_group.m_state = rset->getString(4);
    acct_item_group.m_state_date = rset->getString(5);
    acct_item_group.m_acct_item_group_type = rset->getString(6);

    v_data.push_back(acct_item_group);
}

void AcctItemGroup::prepareSQL()
{
    if (type == 0)
    {
    stmt->setNumber(1,acct_item_group.m_acct_item_group_id);
    stmt->setString(2,acct_item_group.m_acct_item_group_name);
    stmt->setNumber(3,acct_item_group.m_priority);
    stmt->setString(4,acct_item_group.m_state);
    stmt->setString(5,acct_item_group.m_acct_item_group_type);
    }
}

