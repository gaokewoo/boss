#include "Region.hh"

string Region::insSQL="INSERT INTO REGION(REGION_ID,REGION_NAME,REGION_DESC,REGION_LEVEL,REGION_CLASS,STATE,STATE_DATE)VALUES (:REGION_ID,:REGION_NAME,:REGION_DESC,:REGION_LEVEL,:REGION_CLASS,:STATE,SYSDATE)";

string Region::emptySQL="DELETE FROM REGION";

string Region::selectAllSQL="SELECT REGION_ID,REGION_NAME,REGION_DESC,REGION_LEVEL,REGION_CLASS,STATE,TO_CHAR(STATE_DATE,'YYYYMMDDHH24MISS') FROM REGION";

void Region::insertData()
{
    type=0;
    setSQL(insSQL);
    executeUpdate();
}

void Region::emptyData()
{
    type=1;
    setSQL(emptySQL);
    executeUpdate();
}

vector<ST_REGION> Region::loadAllData()
{
    type=2;
    setSQL(selectAllSQL);
    executeQuery();

    return v_data;
}

void Region::doParse()
{
    region.m_region_id = (long)rset->getNumber(1);
    region.m_region_name = rset->getString(2);
    region.m_region_desc = rset->getString(3);
    region.m_region_level = rset->getString(4);
    region.m_region_class = rset->getString(5);
    region.m_state = rset->getString(6);
    region.m_state_date = rset->getString(7);

    v_data.push_back(region);
}

void Region::prepareSQL()
{
    if (type == 0)
    {
    stmt->setNumber(1,region.m_region_id);
    stmt->setString(2,region.m_region_name);
    stmt->setString(3,region.m_region_desc);
    stmt->setString(4,region.m_region_level);
    stmt->setString(5,region.m_region_class);
    stmt->setString(6,region.m_state);
    }
}

