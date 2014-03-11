#include "GroupMemberType.hh"

string GroupMemberType::insSQL="INSERT INTO GROUP_MEMBER_TYPE(MEMBER_TYPE_ID,MEMBER_TYPE_NAME,MEMBER_TYPE_DESC)VALUES (:MEMBER_TYPE_ID,:MEMBER_TYPE_NAME,:MEMBER_TYPE_DESC)";

void GroupMemberType::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void GroupMemberType::prepareSQL()
{
    stmt->setNumber(1,group_member_type.m_member_type_id);
    stmt->setString(2,group_member_type.m_member_type_name);
    stmt->setString(3,group_member_type.m_member_type_desc);
}

