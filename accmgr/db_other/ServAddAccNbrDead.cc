#include "ServAddAccNbrDead.hh"

string ServAddAccNbrDead::insSQL="INSERT INTO SERV_ADD_ACC_NBR_DEAD(SERV_ADD_ACC_NBR_ID,SERV_ID,AGREEMENT_ID,ADD_ACC_NBR,STATE,STATE_DATE,ADD_ACC_NBR_TYPE,DEAD_TIME,DEAD_STAFF_ID,DEAD_OPTSN)VALUES (:SERV_ADD_ACC_NBR_ID,:SERV_ID,:AGREEMENT_ID,:ADD_ACC_NBR,:STATE,SYSDATE,:ADD_ACC_NBR_TYPE,SYSDATE,:DEAD_STAFF_ID,:DEAD_OPTSN)";

void ServAddAccNbrDead::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void ServAddAccNbrDead::prepareSQL()
{
    stmt->setNumber(1,serv_add_acc_nbr_dead.m_serv_add_acc_nbr_id);
    stmt->setNumber(2,serv_add_acc_nbr_dead.m_serv_id);
    stmt->setNumber(3,serv_add_acc_nbr_dead.m_agreement_id);
    stmt->setString(4,serv_add_acc_nbr_dead.m_add_acc_nbr);
    stmt->setString(5,serv_add_acc_nbr_dead.m_state);
    stmt->setString(6,serv_add_acc_nbr_dead.m_add_acc_nbr_type);
    stmt->setNumber(7,serv_add_acc_nbr_dead.m_dead_staff_id);
    stmt->setNumber(8,serv_add_acc_nbr_dead.m_dead_optsn);
}

