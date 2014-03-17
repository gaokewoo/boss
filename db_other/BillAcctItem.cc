#include "BillAcctItem.hh"

string BillAcctItem::insSQL="INSERT INTO BILL_ACCT_ITEM(BILL_ITEM_TYPE_ID,ITEM_SOURCE_ID,ACCT_ITEM_TYPE_ID)VALUES (:BILL_ITEM_TYPE_ID,:ITEM_SOURCE_ID,:ACCT_ITEM_TYPE_ID)";

void BillAcctItem::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void BillAcctItem::prepareSQL()
{
    stmt->setNumber(1,bill_acct_item.m_bill_item_type_id);
    stmt->setNumber(2,bill_acct_item.m_item_source_id);
    stmt->setNumber(3,bill_acct_item.m_acct_item_type_id);
}

