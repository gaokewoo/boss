#include "Owner.hh"

string Owner::insSQL="INSERT INTO OWNER(OWNER_ID,OWNER_OBJECT_TYPE,CHARGE_PARTY_ID)VALUES (:OWNER_ID,:OWNER_OBJECT_TYPE,:CHARGE_PARTY_ID)";

void Owner::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void Owner::prepareSQL()
{
    stmt->setNumber(1,owner.m_owner_id);
    stmt->setString(2,owner.m_owner_object_type);
    stmt->setString(3,owner.m_charge_party_id);
}

