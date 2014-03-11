#include "CdrQueryType.hh"

string CdrQueryType::insSQL="INSERT INTO CDR_QUERY_TYPE(QUERY_TYPE,FEE_NAME,TITLE_NAME)VALUES (:QUERY_TYPE,:FEE_NAME,:TITLE_NAME)";

void CdrQueryType::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void CdrQueryType::prepareSQL()
{
    stmt->setString(1,cdr_query_type.m_query_type);
    stmt->setString(2,cdr_query_type.m_fee_name);
    stmt->setString(3,cdr_query_type.m_title_name);
}

