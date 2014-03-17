#include "PricingSectionType.hh"

string PricingSectionType::insSQL="INSERT INTO PRICING_SECTION_TYPE(SECTION_TYPE_ID,SECTION_TYPE_NAME)VALUES (:SECTION_TYPE_ID,:SECTION_TYPE_NAME)";

void PricingSectionType::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void PricingSectionType::prepareSQL()
{
    stmt->setNumber(1,pricing_section_type.m_section_type_id);
    stmt->setString(2,pricing_section_type.m_section_type_name);
}

