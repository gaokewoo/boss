#include "OweTypeLimit.hh"

string OweTypeLimit::insSQL="INSERT INTO OWE_TYPE_LIMIT(OWE_TYPE_LIMIT_ID,OWE_BUSINESS_TYPE_ID,CREDIT_CEIL,CREDIT_FLOOR,QUANTITY)VALUES (:OWE_TYPE_LIMIT_ID,:OWE_BUSINESS_TYPE_ID,:CREDIT_CEIL,:CREDIT_FLOOR,:QUANTITY)";

void OweTypeLimit::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void OweTypeLimit::prepareSQL()
{
    stmt->setNumber(1,owe_type_limit.m_owe_type_limit_id);
    stmt->setNumber(2,owe_type_limit.m_owe_business_type_id);
    stmt->setNumber(3,owe_type_limit.m_credit_ceil);
    stmt->setNumber(4,owe_type_limit.m_credit_floor);
    stmt->setNumber(5,owe_type_limit.m_quantity);
}

