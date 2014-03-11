#include "PricingSectionRelation.hh"

string PricingSectionRelation::insSQL="INSERT INTO PRICING_SECTION_RELATION(A_SECTION_ID,Z_SECTION_ID,RELATION_TYPE)VALUES (:A_SECTION_ID,:Z_SECTION_ID,:RELATION_TYPE)";

void PricingSectionRelation::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void PricingSectionRelation::prepareSQL()
{
    stmt->setNumber(1,pricing_section_relation.m_a_section_id);
    stmt->setNumber(2,pricing_section_relation.m_z_section_id);
    stmt->setString(3,pricing_section_relation.m_relation_type);
}

