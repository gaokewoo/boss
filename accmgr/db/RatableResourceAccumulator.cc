#include "RatableResourceAccumulator.hh"

string RatableResourceAccumulator::insSQL="INSERT INTO RATABLE_RESOURCE_ACCUMULATOR(RATABLE_RESOURCE_ID,OWNER_TYPE,OWNER_ID,RATABLE_CYCLE_ID,BALANCE,ORIGIN_BALANCE,RATABLE_OBJECT_ID)VALUES (:RATABLE_RESOURCE_ID,:OWNER_TYPE,:OWNER_ID,:RATABLE_CYCLE_ID,:BALANCE,:ORIGIN_BALANCE,:RATABLE_OBJECT_ID)";

void RatableResourceAccumulator::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void RatableResourceAccumulator::prepareSQL()
{
    stmt->setNumber(1,ratable_resource_accumulator.m_ratable_resource_id);
    stmt->setString(2,ratable_resource_accumulator.m_owner_type);
    stmt->setNumber(3,ratable_resource_accumulator.m_owner_id);
    stmt->setNumber(4,ratable_resource_accumulator.m_ratable_cycle_id);
    stmt->setNumber(5,ratable_resource_accumulator.m_balance);
    stmt->setNumber(6,ratable_resource_accumulator.m_origin_balance);
    stmt->setNumber(7,ratable_resource_accumulator.m_ratable_object_id);
}

