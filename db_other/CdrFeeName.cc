#include "CdrFeeName.hh"

string CdrFeeName::insSQL="INSERT INTO CDR_FEE_NAME(REGION_ID,BEGIN_TIME,END_TIME,FEE_NAME)VALUES (:REGION_ID,SYSDATE,SYSDATE,:FEE_NAME)";

void CdrFeeName::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void CdrFeeName::prepareSQL()
{
    stmt->setNumber(1,cdr_fee_name.m_region_id);
    stmt->setString(2,cdr_fee_name.m_fee_name);
}

