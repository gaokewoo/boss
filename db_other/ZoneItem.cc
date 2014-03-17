#include "ZoneItem.hh"

string ZoneItem::insSQL="INSERT INTO ZONE_ITEM(ZONE_ITEM_ID,ZONE_ID,PARENT_ZONE_ITEM_ID,ZONE_ITEM_NAME)VALUES (:ZONE_ITEM_ID,:ZONE_ID,:PARENT_ZONE_ITEM_ID,:ZONE_ITEM_NAME)";

void ZoneItem::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void ZoneItem::prepareSQL()
{
    stmt->setNumber(1,zone_item.m_zone_item_id);
    stmt->setNumber(2,zone_item.m_zone_id);
    stmt->setNumber(3,zone_item.m_parent_zone_item_id);
    stmt->setString(4,zone_item.m_zone_item_name);
}

