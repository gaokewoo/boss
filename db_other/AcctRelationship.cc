#include "AcctRelationship.hh"

string AcctRelationship::insSQL="INSERT INTO ACCT_RELATIONSHIP(ACCT_ID,REL_ACCT_ID,ACCT_REL_TYPE,VALID_AMOUNT)VALUES (:ACCT_ID,:REL_ACCT_ID,:ACCT_REL_TYPE,:VALID_AMOUNT)";

void AcctRelationship::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void AcctRelationship::prepareSQL()
{
    stmt->setNumber(1,acct_relationship.m_acct_id);
    stmt->setNumber(2,acct_relationship.m_rel_acct_id);
    stmt->setString(3,acct_relationship.m_acct_rel_type);
    stmt->setNumber(4,acct_relationship.m_valid_amount);
}

