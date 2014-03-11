#include "CdrCallName.hh"

string CdrCallName::insSQL="INSERT INTO CDR_CALL_NAME(REGION_ID,BEGIN_TIME,END_TIME,CALL_NAME)VALUES (:REGION_ID,SYSDATE,SYSDATE,:CALL_NAME)";

void CdrCallName::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void CdrCallName::prepareSQL()
{
    stmt->setNumber(1,cdr_call_name.m_region_id);
    stmt->setString(2,cdr_call_name.m_call_name);
}

