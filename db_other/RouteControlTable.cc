#include "RouteControlTable.hh"

string RouteControlTable::insSQL="INSERT INTO ROUTE_CONTROL_TABLE(ROUTE_NAME,SYSTEM_TYPE,ROUTE_TYPE,ROUTE_GROUP,ROUTE_FLAG,ROUTE_IP,ROUTE_PORT,QUERY_IP,QUERY_PORT,CHANGE_DATE,SYSTEM_TYPE_NEW,ROUTE_GROUP_NEW,ROUTE_IP_NEW,ROUTE_PORT_NEW,QUERY_IP_NEW,QUERY_PORT_NEW,INSTANCE,SYNC_ID,NOTE,AUDIT_FLAG)VALUES (:ROUTE_NAME,:SYSTEM_TYPE,:ROUTE_TYPE,:ROUTE_GROUP,:ROUTE_FLAG,:ROUTE_IP,:ROUTE_PORT,:QUERY_IP,:QUERY_PORT,SYSDATE,:SYSTEM_TYPE_NEW,:ROUTE_GROUP_NEW,:ROUTE_IP_NEW,:ROUTE_PORT_NEW,:QUERY_IP_NEW,:QUERY_PORT_NEW,:INSTANCE,:SYNC_ID,:NOTE,:AUDIT_FLAG)";

void RouteControlTable::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void RouteControlTable::prepareSQL()
{
    stmt->setString(1,route_control_table.m_route_name);
    stmt->setString(2,route_control_table.m_system_type);
    stmt->setString(3,route_control_table.m_route_type);
    stmt->setString(4,route_control_table.m_route_group);
    stmt->setString(5,route_control_table.m_route_flag);
    stmt->setString(6,route_control_table.m_route_ip);
    stmt->setNumber(7,route_control_table.m_route_port);
    stmt->setString(8,route_control_table.m_query_ip);
    stmt->setNumber(9,route_control_table.m_query_port);
    stmt->setString(10,route_control_table.m_system_type_new);
    stmt->setString(11,route_control_table.m_route_group_new);
    stmt->setString(12,route_control_table.m_route_ip_new);
    stmt->setNumber(13,route_control_table.m_route_port_new);
    stmt->setString(14,route_control_table.m_query_ip_new);
    stmt->setNumber(15,route_control_table.m_query_port_new);
    stmt->setString(16,route_control_table.m_instance);
    stmt->setString(17,route_control_table.m_sync_id);
    stmt->setString(18,route_control_table.m_note);
    stmt->setString(19,route_control_table.m_audit_flag);
}

