#include "NbrImsi.hh"

string NbrImsi::insSQL="INSERT INTO NBR_IMSI(ACC_NBR,IMSI_NO,EFF_DATE,EXP_DATE)VALUES (:ACC_NBR,:IMSI_NO,SYSDATE,SYSDATE)";

void NbrImsi::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void NbrImsi::prepareSQL()
{
    stmt->setString(1,nbr_imsi.m_acc_nbr);
    stmt->setString(2,nbr_imsi.m_imsi_no);
}

