#include "BillItem.hh"

string BillItem::insSQL="INSERT INTO BILL_ITEM(BILL_ITEM_TYPE_ID,CLASSIFY,BILL_PARENT_ID,BILL_REMARK_ID,PRODUCT_OFFER_ID,PRINT_ORDER)VALUES (:BILL_ITEM_TYPE_ID,:CLASSIFY,:BILL_PARENT_ID,:BILL_REMARK_ID,:PRODUCT_OFFER_ID,:PRINT_ORDER)";

void BillItem::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void BillItem::prepareSQL()
{
    stmt->setNumber(1,bill_item.m_bill_item_type_id);
    stmt->setString(2,bill_item.m_classify);
    stmt->setNumber(3,bill_item.m_bill_parent_id);
    stmt->setNumber(4,bill_item.m_bill_remark_id);
    stmt->setNumber(5,bill_item.m_product_offer_id);
    stmt->setNumber(6,bill_item.m_print_order);
}

