#include "ServStateDesc.hh"

string ServStateDesc::insSQL="INSERT INTO SERV_STATE_DESC(STATE,REGION_ID,STATE_NAME)VALUES (:STATE,:REGION_ID,:STATE_NAME)";

void ServStateDesc::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void ServStateDesc::prepareSQL()
{
    stmt->setString(1,serv_state_desc.m_state);
    stmt->setNumber(2,serv_state_desc.m_region_id);
    stmt->setString(3,serv_state_desc.m_state_name);
}

