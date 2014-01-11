#include "MeasureMethod.hh"

string MeasureMethod::insSQL="INSERT INTO MEASURE_METHOD(MEASURE_METHOD_ID,MEASURE_METHOD_NAME)VALUES (:MEASURE_METHOD_ID,:MEASURE_METHOD_NAME)";

void MeasureMethod::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void MeasureMethod::prepareSQL()
{
    stmt->setNumber(1,measure_method.m_measure_method_id);
    stmt->setString(2,measure_method.m_measure_method_name);
}

