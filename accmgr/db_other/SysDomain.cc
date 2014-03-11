#include "SysDomain.hh"

string SysDomain::insSQL="INSERT INTO SYS_DOMAIN(TABLE_NAME,FIELD_NAME,DOMAIN,NAME)VALUES (:TABLE_NAME,:FIELD_NAME,:DOMAIN,:NAME)";

void SysDomain::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void SysDomain::prepareSQL()
{
    stmt->setString(1,sys_domain.m_table_name);
    stmt->setString(2,sys_domain.m_field_name);
    stmt->setString(3,sys_domain.m_domain);
    stmt->setString(4,sys_domain.m_name);
}

