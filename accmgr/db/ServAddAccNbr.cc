#include "ServAddAccNbr.hh"

string ServAddAccNbr::insSQL="INSERT INTO SERV_ADD_ACC_NBR(SERV_ADD_ACC_NBR_ID,SERV_ID,AGREEMENT_ID,ADD_ACC_NBR,STATE,STATE_DATE,ADD_ACC_NBR_TYPE)VALUES (:SERV_ADD_ACC_NBR_ID,:SERV_ID,:AGREEMENT_ID,:ADD_ACC_NBR,:STATE,SYSDATE,:ADD_ACC_NBR_TYPE)";

void ServAddAccNbr::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void ServAddAccNbr::prepareSQL()
{
    stmt->setNumber(1,serv_add_acc_nbr.m_serv_add_acc_nbr_id);
    stmt->setNumber(2,serv_add_acc_nbr.m_serv_id);
    stmt->setNumber(3,serv_add_acc_nbr.m_agreement_id);
    stmt->setString(4,serv_add_acc_nbr.m_add_acc_nbr);
    stmt->setString(5,serv_add_acc_nbr.m_state);
    stmt->setString(6,serv_add_acc_nbr.m_add_acc_nbr_type);
}

