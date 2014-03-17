#include "RatableObject.hh"

string RatableObject::insSQL="INSERT INTO RATABLE_OBJECT(ELEMENT_ID,RATABLE_OBJECT_ID)VALUES (:ELEMENT_ID,:RATABLE_OBJECT_ID)";

void RatableObject::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void RatableObject::prepareSQL()
{
    stmt->setNumber(1,ratable_object.m_element_id);
    stmt->setNumber(2,ratable_object.m_ratable_object_id);
}

