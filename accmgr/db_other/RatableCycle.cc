#include "RatableCycle.hh"

string RatableCycle::insSQL="INSERT INTO RATABLE_CYCLE(RATABLE_CYCLE_ID,RATABLE_CYCLE_TYPE_ID,CYCLE_BEGIN_DATE,CYCLE_END_DATE,STATE,STATE_DATE)VALUES (:RATABLE_CYCLE_ID,:RATABLE_CYCLE_TYPE_ID,SYSDATE,SYSDATE,:STATE,SYSDATE)";

void RatableCycle::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void RatableCycle::prepareSQL()
{
    stmt->setNumber(1,ratable_cycle.m_ratable_cycle_id);
    stmt->setNumber(2,ratable_cycle.m_ratable_cycle_type_id);
    stmt->setString(3,ratable_cycle.m_state);
}

