#include "PropertyRef.hh"

string PropertyRef::insSQL="INSERT INTO PROPERTY_REF(PROPERTY_REF_ID,PROPERTY_DEFINE_ID,REF_TYPE,VALUE_TYPE,VALUE_STRING,REF_FEE_TYPE)VALUES (:PROPERTY_REF_ID,:PROPERTY_DEFINE_ID,:REF_TYPE,:VALUE_TYPE,:VALUE_STRING,:REF_FEE_TYPE)";

void PropertyRef::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void PropertyRef::prepareSQL()
{
    stmt->setNumber(1,property_ref.m_property_ref_id);
    stmt->setNumber(2,property_ref.m_property_define_id);
    stmt->setString(3,property_ref.m_ref_type);
    stmt->setString(4,property_ref.m_value_type);
    stmt->setString(5,property_ref.m_value_string);
    stmt->setString(6,property_ref.m_ref_fee_type);
}

