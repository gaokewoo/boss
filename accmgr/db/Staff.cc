#include "Staff.hh"

string Staff::insSQL="INSERT INTO STAFF(STAFF_ID,OPERATE_ORG_ID,STAFF_CODE,PASSWD,SCOPE_LEVEL,STAFF_DESC,PARENT_PARTYROLEID,STAFF_TYPE)VALUES (:STAFF_ID,:OPERATE_ORG_ID,:STAFF_CODE,:PASSWD,:SCOPE_LEVEL,:STAFF_DESC,:PARENT_PARTYROLEID,:STAFF_TYPE)";

void Staff::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void Staff::prepareSQL()
{
    stmt->setNumber(1,staff.m_staff_id);
    stmt->setNumber(2,staff.m_operate_org_id);
    stmt->setString(3,staff.m_staff_code);
    stmt->setString(4,staff.m_passwd);
    stmt->setString(5,staff.m_scope_level);
    stmt->setString(6,staff.m_staff_desc);
    stmt->setNumber(7,staff.m_parent_partyroleid);
    stmt->setString(8,staff.m_staff_type);
}

