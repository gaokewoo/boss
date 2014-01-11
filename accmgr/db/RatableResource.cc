#include "RatableResource.hh"

string RatableResource::insSQL="INSERT INTO RATABLE_RESOURCE(RATABLE_RESOURCE_ID,ORG_TARIFF_UNIT_ID,RATABLE_RESOURCE_NAME,DEFAULT_RATABLE_CYCLE_TYPE_ID,CAN_BE_NEGATIVE,DURATIVE_TYPE)VALUES (:RATABLE_RESOURCE_ID,:ORG_TARIFF_UNIT_ID,:RATABLE_RESOURCE_NAME,:DEFAULT_RATABLE_CYCLE_TYPE_ID,:CAN_BE_NEGATIVE,:DURATIVE_TYPE)";

void RatableResource::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void RatableResource::prepareSQL()
{
    stmt->setNumber(1,ratable_resource.m_ratable_resource_id);
    stmt->setNumber(2,ratable_resource.m_org_tariff_unit_id);
    stmt->setString(3,ratable_resource.m_ratable_resource_name);
    stmt->setNumber(4,ratable_resource.m_default_ratable_cycle_type_id);
    stmt->setString(5,ratable_resource.m_can_be_negative);
    stmt->setString(6,ratable_resource.m_durative_type);
}

