#include "GroupInstanceRole.hh"

string GroupInstanceRole::insSQL="INSERT INTO GROUP_INSTANCE_ROLE(MEMBER_ROLE_ID,MEMBER_ROLE_NAME,MEMBER_ROLE_DESC)VALUES (:MEMBER_ROLE_ID,:MEMBER_ROLE_NAME,:MEMBER_ROLE_DESC)";

void GroupInstanceRole::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void GroupInstanceRole::prepareSQL()
{
    stmt->setNumber(1,group_instance_role.m_member_role_id);
    stmt->setString(2,group_instance_role.m_member_role_name);
    stmt->setString(3,group_instance_role.m_member_role_desc);
}

