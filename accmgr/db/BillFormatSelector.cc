#include "BillFormatSelector.hh"

string BillFormatSelector::insSQL="INSERT INTO BILL_FORMAT_SELECTOR(BILL_FORMAT_SELECTOR_ID,BILL_FORMAT_CUSTOMIZE_ID,BILL_FORMAT_ID)VALUES (:BILL_FORMAT_SELECTOR_ID,:BILL_FORMAT_CUSTOMIZE_ID,:BILL_FORMAT_ID)";

void BillFormatSelector::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void BillFormatSelector::prepareSQL()
{
    stmt->setNumber(1,bill_format_selector.m_bill_format_selector_id);
    stmt->setNumber(2,bill_format_selector.m_bill_format_customize_id);
    stmt->setNumber(3,bill_format_selector.m_bill_format_id);
}

