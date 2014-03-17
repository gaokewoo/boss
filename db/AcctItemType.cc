#include "AcctItemType.hh"

string AcctItemType::insSQL="INSERT INTO ACCT_ITEM_TYPE(ACCT_ITEM_TYPE_ID,ACCT_ITEM_CLASS_ID,PARTY_ROLE_ID,PRIORITY,NAME,CHARGE_MARK,TOTAL_MARK,ACCT_ITEM_TYPE_CODE,PARENT_ITEM_TYPE_ID)VALUES (:ACCT_ITEM_TYPE_ID,:ACCT_ITEM_CLASS_ID,:PARTY_ROLE_ID,:PRIORITY,:NAME,:CHARGE_MARK,:TOTAL_MARK,:ACCT_ITEM_TYPE_CODE,:PARENT_ITEM_TYPE_ID)";

string AcctItemType::emptySQL="DELETE FROM ACCT_ITEM_TYPE";

string AcctItemType::selectAllSQL="SELECT ACCT_ITEM_TYPE_ID,ACCT_ITEM_CLASS_ID,PARTY_ROLE_ID,PRIORITY,NAME,CHARGE_MARK,TOTAL_MARK,ACCT_ITEM_TYPE_CODE,PARENT_ITEM_TYPE_ID FROM ACCT_ITEM_TYPE";

void AcctItemType::insertData()
{
    type=0;
    setSQL(insSQL);
    executeUpdate();
}

void AcctItemType::emptyData()
{
    type=1;
    setSQL(emptySQL);
    executeUpdate();
}

vector<ST_ACCT_ITEM_TYPE> AcctItemType::loadAllData()
{
    type=2;
    setSQL(selectAllSQL);
    executeQuery();

    return v_data;
}

void AcctItemType::doParse()
{
    acct_item_type.m_acct_item_type_id = (long)rset->getNumber(1);
    acct_item_type.m_acct_item_class_id = (long)rset->getNumber(2);
    acct_item_type.m_party_role_id = (long)rset->getNumber(3);
    acct_item_type.m_priority = (long)rset->getNumber(4);
    acct_item_type.m_name = rset->getString(5);
    acct_item_type.m_charge_mark = rset->getString(6);
    acct_item_type.m_total_mark = rset->getString(7);
    acct_item_type.m_acct_item_type_code = rset->getString(8);
    acct_item_type.m_parent_item_type_id = (long)rset->getNumber(9);

    v_data.push_back(acct_item_type);
}

void AcctItemType::prepareSQL()
{
    if (type == 0)
    {
    stmt->setNumber(1,acct_item_type.m_acct_item_type_id);
    stmt->setNumber(2,acct_item_type.m_acct_item_class_id);
    stmt->setNumber(3,acct_item_type.m_party_role_id);
    stmt->setNumber(4,acct_item_type.m_priority);
    stmt->setString(5,acct_item_type.m_name);
    stmt->setString(6,acct_item_type.m_charge_mark);
    stmt->setString(7,acct_item_type.m_total_mark);
    stmt->setString(8,acct_item_type.m_acct_item_type_code);
    stmt->setNumber(9,acct_item_type.m_parent_item_type_id);
    }
}

