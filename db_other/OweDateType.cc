#include "OweDateType.hh"

string OweDateType::insSQL="INSERT INTO OWE_DATE_TYPE(DATE_TYPE_ID,DATE_TYPE_CODE,DATE_TYPE_NAME)VALUES (:DATE_TYPE_ID,:DATE_TYPE_CODE,:DATE_TYPE_NAME)";

void OweDateType::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void OweDateType::prepareSQL()
{
    stmt->setNumber(1,owe_date_type.m_date_type_id);
    stmt->setString(2,owe_date_type.m_date_type_code);
    stmt->setString(3,owe_date_type.m_date_type_name);
}

