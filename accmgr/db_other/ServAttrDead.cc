#include "ServAttrDead.hh"

string ServAttrDead::insSQL="INSERT INTO SERV_ATTR_DEAD(SERV_ID,AGREEMENT_ID,ATTR_ID,ATTR_VAL,EFF_DATE,EXP_DATE,DEAD_TIME,DEAD_STAFF_ID,DEAD_OPTSN)VALUES (:SERV_ID,:AGREEMENT_ID,:ATTR_ID,:ATTR_VAL,SYSDATE,SYSDATE,SYSDATE,:DEAD_STAFF_ID,:DEAD_OPTSN)";

void ServAttrDead::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void ServAttrDead::prepareSQL()
{
    stmt->setNumber(1,serv_attr_dead.m_serv_id);
    stmt->setNumber(2,serv_attr_dead.m_agreement_id);
    stmt->setNumber(3,serv_attr_dead.m_attr_id);
    stmt->setString(4,serv_attr_dead.m_attr_val);
    stmt->setNumber(5,serv_attr_dead.m_dead_staff_id);
    stmt->setNumber(6,serv_attr_dead.m_dead_optsn);
}

