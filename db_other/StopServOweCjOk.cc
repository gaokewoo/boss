#include "StopServOweCjOk.hh"

string StopServOweCjOk::insSQL="INSERT INTO STOP_SERV_OWE_CJ_OK(ACC_NBR,SERV_ID)VALUES (:ACC_NBR,:SERV_ID)";

void StopServOweCjOk::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void StopServOweCjOk::prepareSQL()
{
    stmt->setString(1,stop_serv_owe_cj_ok.m_acc_nbr);
    stmt->setNumber(2,stop_serv_owe_cj_ok.m_serv_id);
}

