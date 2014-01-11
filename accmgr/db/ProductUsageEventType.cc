#include "ProductUsageEventType.hh"

string ProductUsageEventType::insSQL="INSERT INTO PRODUCT_USAGE_EVENT_TYPE(PRODUCT_ID,EVENT_TYPE_ID,EFF_DATE,EXP_DATE)VALUES (:PRODUCT_ID,:EVENT_TYPE_ID,SYSDATE,SYSDATE)";

void ProductUsageEventType::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void ProductUsageEventType::prepareSQL()
{
    stmt->setNumber(1,product_usage_event_type.m_product_id);
    stmt->setNumber(2,product_usage_event_type.m_event_type_id);
}

