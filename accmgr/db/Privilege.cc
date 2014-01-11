#include "Privilege.hh"

string Privilege::insSQL="INSERT INTO PRIVILEGE(PRIVILEGE_ID,PARENT_PRIVILEGEID,PRIVILEGE_NAME,PRIVILEGE_TYPE,APP_CODE,PRIVILEGE_DESC)VALUES (:PRIVILEGE_ID,:PARENT_PRIVILEGEID,:PRIVILEGE_NAME,:PRIVILEGE_TYPE,:APP_CODE,:PRIVILEGE_DESC)";

void Privilege::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void Privilege::prepareSQL()
{
    stmt->setNumber(1,privilege.m_privilege_id);
    stmt->setNumber(2,privilege.m_parent_privilegeid);
    stmt->setString(3,privilege.m_privilege_name);
    stmt->setString(4,privilege.m_privilege_type);
    stmt->setString(5,privilege.m_app_code);
    stmt->setString(6,privilege.m_privilege_desc);
}

