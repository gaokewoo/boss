#include "AcctItemType.hh"

string AcctItemType::insSQL="INSERT INTO ACCT_ITEM_TYPE(ACCT_ITEM_TYPE_ID,ACCT_ITEM_CLASS_ID,PARTY_ROLE_ID,PRIORITY,NAME,CHARGE_MARK,TOTAL_MARK,ACCT_ITEM_TYPE_CODE,PARENT_ITEM_TYPE_ID)VALUES (:ACCT_ITEM_TYPE_ID,:ACCT_ITEM_CLASS_ID,:PARTY_ROLE_ID,:PRIORITY,:NAME,:CHARGE_MARK,:TOTAL_MARK,:ACCT_ITEM_TYPE_CODE,:PARENT_ITEM_TYPE_ID)";

void AcctItemType::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void AcctItemType::prepareSQL()
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

