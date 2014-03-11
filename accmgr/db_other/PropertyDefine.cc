#include "PropertyDefine.hh"

string PropertyDefine::insSQL="INSERT INTO PROPERTY_DEFINE(PROPERTY_DEFINE_ID,DEFAULT_VALUE,PROPERTY_DESC)VALUES (:PROPERTY_DEFINE_ID,:DEFAULT_VALUE,:PROPERTY_DESC)";

void PropertyDefine::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void PropertyDefine::prepareSQL()
{
    stmt->setNumber(1,property_define.m_property_define_id);
    stmt->setString(2,property_define.m_default_value);
    stmt->setString(3,property_define.m_property_desc);
}

