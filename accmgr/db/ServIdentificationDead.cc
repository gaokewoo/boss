#include "ServIdentificationDead.hh"

string ServIdentificationDead::insSQL="INSERT INTO SERV_IDENTIFICATION_DEAD(SERV_ID,AGREEMENT_ID,ACC_NBR,EFF_DATE,EXP_DATE,DEAD_TIME,DEAD_STAFF_ID,DEAD_OPTSN)VALUES (:SERV_ID,:AGREEMENT_ID,:ACC_NBR,SYSDATE,SYSDATE,SYSDATE,:DEAD_STAFF_ID,:DEAD_OPTSN)";

void ServIdentificationDead::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void ServIdentificationDead::prepareSQL()
{
    stmt->setNumber(1,serv_identification_dead.m_serv_id);
    stmt->setNumber(2,serv_identification_dead.m_agreement_id);
    stmt->setString(3,serv_identification_dead.m_acc_nbr);
    stmt->setNumber(4,serv_identification_dead.m_dead_staff_id);
    stmt->setNumber(5,serv_identification_dead.m_dead_optsn);
}

