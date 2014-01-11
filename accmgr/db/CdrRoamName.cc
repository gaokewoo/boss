#include "CdrRoamName.hh"

string CdrRoamName::insSQL="INSERT INTO CDR_ROAM_NAME(REGION_ID,BEGIN_TIME,END_TIME,ROAM_NAME)VALUES (:REGION_ID,SYSDATE,SYSDATE,:ROAM_NAME)";

void CdrRoamName::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void CdrRoamName::prepareSQL()
{
    stmt->setNumber(1,cdr_roam_name.m_region_id);
    stmt->setString(2,cdr_roam_name.m_roam_name);
}

