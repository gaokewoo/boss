#include "RatableCycleType.hh"

string RatableCycleType::insSQL="INSERT INTO RATABLE_CYCLE_TYPE(RATABLE_CYCLE_TYPE_ID,RATABLE_CYCLE_TYPE_NAME,CYCLE_UNIT,UNIT_COUNT,CYCLE_DURATION,CYCLE_DURATION_DAYS,OFFSET_TIME)VALUES (:RATABLE_CYCLE_TYPE_ID,:RATABLE_CYCLE_TYPE_NAME,:CYCLE_UNIT,:UNIT_COUNT,:CYCLE_DURATION,:CYCLE_DURATION_DAYS,:OFFSET_TIME)";

void RatableCycleType::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void RatableCycleType::prepareSQL()
{
    stmt->setNumber(1,ratable_cycle_type.m_ratable_cycle_type_id);
    stmt->setString(2,ratable_cycle_type.m_ratable_cycle_type_name);
    stmt->setString(3,ratable_cycle_type.m_cycle_unit);
    stmt->setNumber(4,ratable_cycle_type.m_unit_count);
    stmt->setNumber(5,ratable_cycle_type.m_cycle_duration);
    stmt->setNumber(6,ratable_cycle_type.m_cycle_duration_days);
    stmt->setNumber(7,ratable_cycle_type.m_offset_time);
}

