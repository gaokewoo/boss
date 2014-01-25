#include "ServStateDesc.hh"

string ServStateDesc::insSQL="INSERT INTO SERV_STATE_DESC(STATE,REGION_ID,STATE_NAME)VALUES (:STATE,:REGION_ID,:STATE_NAME)";

string ServStateDesc::emptySQL="DELETE FROM SERV_STATE_DESC";

string ServStateDesc::selectAllSQL="SELECT STATE,REGION_ID,STATE_NAME FROM SERV_STATE_DESC";

void ServStateDesc::insertData()
{
    type=0;
    setSQL(insSQL);
    executeUpdate();
}

void ServStateDesc::emptyData()
{
    type=1;
    setSQL(emptySQL);
    executeUpdate();
}

vector<ST_SERV_STATE_DESC> ServStateDesc::loadAllData()
{
    type=2;
    setSQL(selectAllSQL);
    executeQuery();

    return v_data;
}

void ServStateDesc::doParse()
{
    serv_state_desc.m_state = rset->getString(1);
    serv_state_desc.m_region_id = (long)rset->getNumber(2);
    serv_state_desc.m_state_name = rset->getString(3);

    v_data.push_back(serv_state_desc);
}

void ServStateDesc::prepareSQL()
{
    if (type == 0)
    {
    stmt->setString(1,serv_state_desc.m_state);
    stmt->setNumber(2,serv_state_desc.m_region_id);
    stmt->setString(3,serv_state_desc.m_state_name);
    }
}

