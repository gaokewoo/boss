#include "OweTypeAccttype.hh"

string OweTypeAccttype::insSQL="INSERT INTO OWE_TYPE_ACCTTYPE(ACCT_ITEM_TYPE_ID,OWE_BUSINESS_TYPE_ID)VALUES (:ACCT_ITEM_TYPE_ID,:OWE_BUSINESS_TYPE_ID)";

void OweTypeAccttype::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void OweTypeAccttype::prepareSQL()
{
    stmt->setNumber(1,owe_type_accttype.m_acct_item_type_id);
    stmt->setNumber(2,owe_type_accttype.m_owe_business_type_id);
}

