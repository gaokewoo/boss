#include "LogicalAddress.hh"

string LogicalAddress::insSQL="INSERT INTO LOGICAL_ADDRESS(LOGICAL_ADDRESS_ID,ADDRESS_ID,LOGICAL_ADDRESS_TYPE,LOGICAL_ADDRESS_DETAIL)VALUES (:LOGICAL_ADDRESS_ID,:ADDRESS_ID,:LOGICAL_ADDRESS_TYPE,:LOGICAL_ADDRESS_DETAIL)";

void LogicalAddress::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void LogicalAddress::prepareSQL()
{
    stmt->setNumber(1,logical_address.m_logical_address_id);
    stmt->setNumber(2,logical_address.m_address_id);
    stmt->setString(3,logical_address.m_logical_address_type);
    stmt->setString(4,logical_address.m_logical_address_detail);
}

