#include "Partner.hh"

string Partner::insSQL="INSERT INTO PARTNER(PARTY_ID,PARD_CODE,PARD_TYPE,PARD_DESC)VALUES (:PARTY_ID,:PARD_CODE,:PARD_TYPE,:PARD_DESC)";

void Partner::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void Partner::prepareSQL()
{
    stmt->setNumber(1,partner.m_party_id);
    stmt->setString(2,partner.m_pard_code);
    stmt->setString(3,partner.m_pard_type);
    stmt->setString(4,partner.m_pard_desc);
}

