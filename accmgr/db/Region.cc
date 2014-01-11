#include "Region.hh"

string Region::insSQL="INSERT INTO REGION(REGION_ID,REGION_NAME,REGION_DESC,REGION_LEVEL,REGION_CLASS,STATE,STATE_DATE)VALUES (:REGION_ID,:REGION_NAME,:REGION_DESC,:REGION_LEVEL,:REGION_CLASS,:STATE,SYSDATE)";

void Region::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void Region::prepareSQL()
{
    stmt->setNumber(1,region.m_region_id);
    stmt->setString(2,region.m_region_name);
    stmt->setString(3,region.m_region_desc);
    stmt->setString(4,region.m_region_level);
    stmt->setString(5,region.m_region_class);
    stmt->setString(6,region.m_state);
}

