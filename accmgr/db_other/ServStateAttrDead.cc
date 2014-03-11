#include "ServStateAttrDead.hh"

string ServStateAttrDead::insSQL="INSERT INTO SERV_STATE_ATTR_DEAD(SERV_ID,BILLING_CYCLE_TYPE_ID,AGREEMENT_ID,OWE_BUSINESS_TYPE_ID,STATE,EFF_DATE,EXP_DATE,DEAD_TIME,DEAD_STAFF_ID,DEAD_OPTSN)VALUES (:SERV_ID,:BILLING_CYCLE_TYPE_ID,:AGREEMENT_ID,:OWE_BUSINESS_TYPE_ID,:STATE,SYSDATE,SYSDATE,SYSDATE,:DEAD_STAFF_ID,:DEAD_OPTSN)";

void ServStateAttrDead::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void ServStateAttrDead::prepareSQL()
{
    stmt->setNumber(1,serv_state_attr_dead.m_serv_id);
    stmt->setNumber(2,serv_state_attr_dead.m_billing_cycle_type_id);
    stmt->setNumber(3,serv_state_attr_dead.m_agreement_id);
    stmt->setNumber(4,serv_state_attr_dead.m_owe_business_type_id);
    stmt->setString(5,serv_state_attr_dead.m_state);
    stmt->setNumber(6,serv_state_attr_dead.m_dead_staff_id);
    stmt->setNumber(7,serv_state_attr_dead.m_dead_optsn);
}

