#include "StaffPrivilege.hh"

string StaffPrivilege::insSQL="INSERT INTO STAFF_PRIVILEGE(STAFF_ID,PRIVILEGE_ID)VALUES (:STAFF_ID,:PRIVILEGE_ID)";

void StaffPrivilege::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void StaffPrivilege::prepareSQL()
{
    stmt->setNumber(1,staff_privilege.m_staff_id);
    stmt->setNumber(2,staff_privilege.m_privilege_id);
}

