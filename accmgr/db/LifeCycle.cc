#include "LifeCycle.hh"

string LifeCycle::insSQL="INSERT INTO LIFE_CYCLE(LIFE_CYCLE_ID,STATE,EFF_TYPE,EFF_DATE,EXP_DATE,EFF_VALUE,EXP_VALUE,GROUP_ID,CONSTRAINT)VALUES (:LIFE_CYCLE_ID,:STATE,:EFF_TYPE,SYSDATE,SYSDATE,:EFF_VALUE,:EXP_VALUE,:GROUP_ID,:CONSTRAINT)";

void LifeCycle::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void LifeCycle::prepareSQL()
{
    stmt->setNumber(1,life_cycle.m_life_cycle_id);
    stmt->setString(2,life_cycle.m_state);
    stmt->setString(3,life_cycle.m_eff_type);
    stmt->setString(4,life_cycle.m_eff_value);
    stmt->setString(5,life_cycle.m_exp_value);
    stmt->setString(6,life_cycle.m_group_id);
    stmt->setString(7,life_cycle.m_constraint);
}

