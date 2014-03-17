#include "RefValue.hh"

string RefValue::insSQL="INSERT INTO REF_VALUE(REF_VALUE_ID,REF_VALUE_TYPE,VALUE_TYPE,PRICING_REF_OBJECT_ID,VALUE_STRING,PRICING_PRARM_ID,RATE_PRECISION,CALC_PRECISION)VALUES (:REF_VALUE_ID,:REF_VALUE_TYPE,:VALUE_TYPE,:PRICING_REF_OBJECT_ID,:VALUE_STRING,:PRICING_PRARM_ID,:RATE_PRECISION,:CALC_PRECISION)";

void RefValue::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void RefValue::prepareSQL()
{
    stmt->setNumber(1,ref_value.m_ref_value_id);
    stmt->setString(2,ref_value.m_ref_value_type);
    stmt->setString(3,ref_value.m_value_type);
    stmt->setNumber(4,ref_value.m_pricing_ref_object_id);
    stmt->setString(5,ref_value.m_value_string);
    stmt->setNumber(6,ref_value.m_pricing_prarm_id);
    stmt->setNumber(7,ref_value.m_rate_precision);
    stmt->setNumber(8,ref_value.m_calc_precision);
}

