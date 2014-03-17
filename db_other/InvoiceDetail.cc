#include "InvoiceDetail.hh"

string InvoiceDetail::insSQL="INSERT INTO INVOICE_DETAIL(INVOICE_ID,INVOICE_ITEM_ID,ITEM_NAME,ITEM_VALUE)VALUES (:INVOICE_ID,:INVOICE_ITEM_ID,:ITEM_NAME,:ITEM_VALUE)";

void InvoiceDetail::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void InvoiceDetail::prepareSQL()
{
    stmt->setNumber(1,invoice_detail.m_invoice_id);
    stmt->setNumber(2,invoice_detail.m_invoice_item_id);
    stmt->setString(3,invoice_detail.m_item_name);
    stmt->setString(4,invoice_detail.m_item_value);
}

