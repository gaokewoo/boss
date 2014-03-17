#include "BillVariable.hh"

string BillVariable::insSQL="INSERT INTO BILL_VARIABLE(BILL_VARIABLE_ID,BILL_VARIABLE_NAME)VALUES (:BILL_VARIABLE_ID,:BILL_VARIABLE_NAME)";

void BillVariable::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void BillVariable::prepareSQL()
{
    stmt->setNumber(1,bill_variable.m_bill_variable_id);
    stmt->setString(2,bill_variable.m_bill_variable_name);
}

