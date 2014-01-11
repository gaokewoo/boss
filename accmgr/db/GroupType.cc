#include "GroupType.hh"

string GroupType::insSQL="INSERT INTO GROUP_TYPE(GROUP_TYPE_ID,GROUP_TYPE_NAME,GROUP_TYPE_DESC,GROUP_MEB_FLAG)VALUES (:GROUP_TYPE_ID,:GROUP_TYPE_NAME,:GROUP_TYPE_DESC,:GROUP_MEB_FLAG)";

void GroupType::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void GroupType::prepareSQL()
{
    stmt->setNumber(1,group_type.m_group_type_id);
    stmt->setString(2,group_type.m_group_type_name);
    stmt->setString(3,group_type.m_group_type_desc);
    stmt->setString(4,group_type.m_group_meb_flag);
}

