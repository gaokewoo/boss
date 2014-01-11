#include "AggregateObject.hh"

string AggregateObject::insSQL="INSERT INTO AGGREGATE_OBJECT(BELONG_CALC_OBJECT_ID,SUB_CALC_OBJECT_ID,CALC_DIRECTION)VALUES (:BELONG_CALC_OBJECT_ID,:SUB_CALC_OBJECT_ID,:CALC_DIRECTION)";

void AggregateObject::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void AggregateObject::prepareSQL()
{
    stmt->setNumber(1,aggregate_object.m_belong_calc_object_id);
    stmt->setNumber(2,aggregate_object.m_sub_calc_object_id);
    stmt->setString(3,aggregate_object.m_calc_direction);
}

