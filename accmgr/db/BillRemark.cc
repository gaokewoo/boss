#include "BillRemark.hh"

string BillRemark::insSQL="INSERT INTO BILL_REMARK(BILL_REMARK_ID,BILL_VARIABLE_ID,PRINT_CONDITION,PRINT_FORMAT,CONTENT,PRINT_LINE,PRINT_POSITION,PRINT_LENGTH)VALUES (:BILL_REMARK_ID,:BILL_VARIABLE_ID,:PRINT_CONDITION,:PRINT_FORMAT,:CONTENT,:PRINT_LINE,:PRINT_POSITION,:PRINT_LENGTH)";

void BillRemark::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void BillRemark::prepareSQL()
{
    stmt->setNumber(1,bill_remark.m_bill_remark_id);
    stmt->setNumber(2,bill_remark.m_bill_variable_id);
    stmt->setString(3,bill_remark.m_print_condition);
    stmt->setString(4,bill_remark.m_print_format);
    stmt->setString(5,bill_remark.m_content);
    stmt->setNumber(6,bill_remark.m_print_line);
    stmt->setNumber(7,bill_remark.m_print_position);
    stmt->setNumber(8,bill_remark.m_print_length);
}

