#include "BillFormat.hh"

string BillFormat::insSQL="INSERT INTO BILL_FORMAT(BILL_FORMAT_ID,BILL_REMARK_ID,FORMAT_NAME)VALUES (:BILL_FORMAT_ID,:BILL_REMARK_ID,:FORMAT_NAME)";

void BillFormat::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void BillFormat::prepareSQL()
{
    stmt->setNumber(1,bill_format.m_bill_format_id);
    stmt->setNumber(2,bill_format.m_bill_remark_id);
    stmt->setString(3,bill_format.m_format_name);
}

