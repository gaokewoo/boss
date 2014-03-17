#include "AcctItemGroupMember.hh"

string AcctItemGroupMember::insSQL="INSERT INTO ACCT_ITEM_GROUP_MEMBER(ITEM_SOURCE_ID,ACCT_ITEM_TYPE_ID,ACCT_ITEM_GROUP_ID,STATE,STATE_DATE)VALUES (:ITEM_SOURCE_ID,:ACCT_ITEM_TYPE_ID,:ACCT_ITEM_GROUP_ID,:STATE,SYSDATE)";

string AcctItemGroupMember::emptySQL="DELETE FROM ACCT_ITEM_GROUP_MEMBER";

string AcctItemGroupMember::selectAllSQL="SELECT ITEM_SOURCE_ID,ACCT_ITEM_TYPE_ID,ACCT_ITEM_GROUP_ID,STATE,TO_CHAR(STATE_DATE,'YYYYMMDDHH24MISS') FROM ACCT_ITEM_GROUP_MEMBER";

void AcctItemGroupMember::insertData()
{
    type=0;
    setSQL(insSQL);
    executeUpdate();
}

void AcctItemGroupMember::emptyData()
{
    type=1;
    setSQL(emptySQL);
    executeUpdate();
}

vector<ST_ACCT_ITEM_GROUP_MEMBER> AcctItemGroupMember::loadAllData()
{
    type=2;
    setSQL(selectAllSQL);
    executeQuery();

    return v_data;
}

void AcctItemGroupMember::doParse()
{
    acct_item_group_member.m_item_source_id = (long)rset->getNumber(1);
    acct_item_group_member.m_acct_item_type_id = (long)rset->getNumber(2);
    acct_item_group_member.m_acct_item_group_id = (long)rset->getNumber(3);
    acct_item_group_member.m_state = rset->getString(4);
    acct_item_group_member.m_state_date = rset->getString(5);

    v_data.push_back(acct_item_group_member);
}

void AcctItemGroupMember::prepareSQL()
{
    if (type == 0)
    {
    stmt->setNumber(1,acct_item_group_member.m_item_source_id);
    stmt->setNumber(2,acct_item_group_member.m_acct_item_type_id);
    stmt->setNumber(3,acct_item_group_member.m_acct_item_group_id);
    stmt->setString(4,acct_item_group_member.m_state);
    }
}

