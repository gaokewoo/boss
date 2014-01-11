#include "Zone.hh"

string Zone::insSQL="INSERT INTO ZONE(ZONE_ID,PRICING_REF_OBJECT_ID,ZONE_NAME)VALUES (:ZONE_ID,:PRICING_REF_OBJECT_ID,:ZONE_NAME)";

void Zone::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void Zone::prepareSQL()
{
    stmt->setNumber(1,zone.m_zone_id);
    stmt->setNumber(2,zone.m_pricing_ref_object_id);
    stmt->setString(3,zone.m_zone_name);
}

