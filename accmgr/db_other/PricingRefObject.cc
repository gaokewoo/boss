#include "PricingRefObject.hh"

string PricingRefObject::insSQL="INSERT INTO PRICING_REF_OBJECT(PRICING_REF_OBJECT_ID,OWNER_ID,PROPERTY_TYPE,PROPERTY_DEFINE_ID,EXTERN_PROPERTY_STRING,MEASURE_METHOD_ID,HISTORY_TIME_TYPE,HISTORY_TIME_DURATION,HISTORY_TIME_QUANTITY)VALUES (:PRICING_REF_OBJECT_ID,:OWNER_ID,:PROPERTY_TYPE,:PROPERTY_DEFINE_ID,:EXTERN_PROPERTY_STRING,:MEASURE_METHOD_ID,:HISTORY_TIME_TYPE,:HISTORY_TIME_DURATION,:HISTORY_TIME_QUANTITY)";

void PricingRefObject::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void PricingRefObject::prepareSQL()
{
    stmt->setNumber(1,pricing_ref_object.m_pricing_ref_object_id);
    stmt->setNumber(2,pricing_ref_object.m_owner_id);
    stmt->setString(3,pricing_ref_object.m_property_type);
    stmt->setNumber(4,pricing_ref_object.m_property_define_id);
    stmt->setString(5,pricing_ref_object.m_extern_property_string);
    stmt->setNumber(6,pricing_ref_object.m_measure_method_id);
    stmt->setString(7,pricing_ref_object.m_history_time_type);
    stmt->setNumber(8,pricing_ref_object.m_history_time_duration);
    stmt->setNumber(9,pricing_ref_object.m_history_time_quantity);
}

