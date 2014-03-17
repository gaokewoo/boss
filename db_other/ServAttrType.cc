#include "ServAttrType.hh"

string ServAttrType::insSQL="INSERT INTO SERV_ATTR_TYPE(ATTR_ID,ATTR_DESC)VALUES (:ATTR_ID,:ATTR_DESC)";

void ServAttrType::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void ServAttrType::prepareSQL()
{
    stmt->setNumber(1,serv_attr_type.m_attr_id);
    stmt->setString(2,serv_attr_type.m_attr_desc);
}

