#include "ZoneItemValue.hh"

string ZoneItemValue::insSQL="INSERT INTO ZONE_ITEM_VALUE(ITEM_REF_ID,ZONE_ITEM_ID,ITEM_REF_VALUE)VALUES (:ITEM_REF_ID,:ZONE_ITEM_ID,:ITEM_REF_VALUE)";

void ZoneItemValue::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void ZoneItemValue::prepareSQL()
{
    stmt->setNumber(1,zone_item_value.m_item_ref_id);
    stmt->setNumber(2,zone_item_value.m_zone_item_id);
    stmt->setString(3,zone_item_value.m_item_ref_value);
}

