#include "ServIdentification.hh"

string ServIdentification::insSQL="INSERT INTO SERV_IDENTIFICATION(SERV_ID,AGREEMENT_ID,ACC_NBR,EFF_DATE,EXP_DATE)VALUES (:SERV_ID,:AGREEMENT_ID,:ACC_NBR,SYSDATE,SYSDATE+365)";

void ServIdentification::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void ServIdentification::prepareSQL()
{
    stmt->setNumber(1,serv_identification.m_serv_id);
    stmt->setNumber(2,serv_identification.m_agreement_id);
    stmt->setString(3,serv_identification.m_acc_nbr);
}

