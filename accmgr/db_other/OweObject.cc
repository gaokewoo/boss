#include "OweObject.hh"

string OweObject::insSQL="INSERT INTO OWE_OBJECT(OWE_OBJECT_ID,OWE_OBJECT_TYPE,OWE_OBJECT_DESC)VALUES (:OWE_OBJECT_ID,:OWE_OBJECT_TYPE,:OWE_OBJECT_DESC)";

void OweObject::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void OweObject::prepareSQL()
{
    stmt->setNumber(1,owe_object.m_owe_object_id);
    stmt->setString(2,owe_object.m_owe_object_type);
    stmt->setString(3,owe_object.m_owe_object_desc);
}

