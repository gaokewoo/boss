#include "CdrQueryCode.hh"

string CdrQueryCode::insSQL="INSERT INTO CDR_QUERY_CODE(QUERY_CODE,QUERY_TYPE)VALUES (:QUERY_CODE,:QUERY_TYPE)";

void CdrQueryCode::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void CdrQueryCode::prepareSQL()
{
    stmt->setNumber(1,cdr_query_code.m_query_code);
    stmt->setString(2,cdr_query_code.m_query_type);
}

