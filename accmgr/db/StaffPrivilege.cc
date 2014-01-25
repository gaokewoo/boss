#include "StaffPrivilege.hh"

string StaffPrivilege::insSQL="INSERT INTO STAFF_PRIVILEGE(STAFF_ID,PRIVILEGE_ID)VALUES (:STAFF_ID,:PRIVILEGE_ID)";

string StaffPrivilege::emptySQL="DELETE FROM STAFF_PRIVILEGE";

string StaffPrivilege::selectAllSQL="SELECT STAFF_ID,PRIVILEGE_ID FROM STAFF_PRIVILEGE";

void StaffPrivilege::insertData()
{
    type=0;
    setSQL(insSQL);
    executeUpdate();
}

void StaffPrivilege::emptyData()
{
    type=1;
    setSQL(emptySQL);
    executeUpdate();
}

vector<ST_STAFF_PRIVILEGE> StaffPrivilege::loadAllData()
{
    type=2;
    setSQL(selectAllSQL);
    executeQuery();

    return v_data;
}

void StaffPrivilege::doParse()
{
    staff_privilege.m_staff_id = (long)rset->getNumber(1);
    staff_privilege.m_privilege_id = (long)rset->getNumber(2);

    v_data.push_back(staff_privilege);
}

void StaffPrivilege::prepareSQL()
{
    if (type == 0)
    {
    stmt->setNumber(1,staff_privilege.m_staff_id);
    stmt->setNumber(2,staff_privilege.m_privilege_id);
    }
}

