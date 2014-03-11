#include "AcctItemClass.hh"

string AcctItemClass::insSQL="INSERT INTO ACCT_ITEM_CLASS(ACCT_ITEM_CLASS_ID,COMMENTS,ACCT_ITEM_CLASS_CODE)VALUES (:ACCT_ITEM_CLASS_ID,:COMMENTS,:ACCT_ITEM_CLASS_CODE)";

void AcctItemClass::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void AcctItemClass::prepareSQL()
{
    stmt->setNumber(1,acct_item_class.m_acct_item_class_id);
    stmt->setString(2,acct_item_class.m_comments);
    stmt->setString(3,acct_item_class.m_acct_item_class_code);
}

