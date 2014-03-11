#include "BillFormatItem.hh"

string BillFormatItem::insSQL="INSERT INTO BILL_FORMAT_ITEM(BILL_FORMAT_ID,BILL_ITEM_TYPE_ID,PRINT_ORDER)VALUES (:BILL_FORMAT_ID,:BILL_ITEM_TYPE_ID,:PRINT_ORDER)";

void BillFormatItem::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void BillFormatItem::prepareSQL()
{
    stmt->setNumber(1,bill_format_item.m_bill_format_id);
    stmt->setNumber(2,bill_format_item.m_bill_item_type_id);
    stmt->setNumber(3,bill_format_item.m_print_order);
}

