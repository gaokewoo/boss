#include "Address.hh"

string Address::insSQL="INSERT INTO ADDRESS(ADDRESS_ID,PROVINCE_NAME,CITY_NAME,STREET_NAME,STREET_NBR,DETAIL,POSTCODE)VALUES (:ADDRESS_ID,:PROVINCE_NAME,:CITY_NAME,:STREET_NAME,:STREET_NBR,:DETAIL,:POSTCODE)";

string Address::emptySQL="DELETE FROM ADDRESS";

string Address::selectAllSQL="SELECT ADDRESS_ID,PROVINCE_NAME,CITY_NAME,STREET_NAME,STREET_NBR,DETAIL,POSTCODE FROM ADDRESS";

void Address::insertData()
{
    type=0;
    setSQL(insSQL);
    executeUpdate();
}

void Address::emptyData()
{
    type=1;
    setSQL(emptySQL);
    executeUpdate();
}

vector<ST_ADDRESS> Address::loadAllData()
{
    type=2;
    setSQL(selectAllSQL);
    executeQuery();

    return v_data;
}

void Address::doParse()
{
    address.m_address_id = (long)rset->getNumber(1);
    address.m_province_name = rset->getString(2);
    address.m_city_name = rset->getString(3);
    address.m_street_name = rset->getString(4);
    address.m_street_nbr = rset->getString(5);
    address.m_detail = rset->getString(6);
    address.m_postcode = rset->getString(7);

    v_data.push_back(address);
}

void Address::prepareSQL()
{
    if (type == 0)
    {
    stmt->setNumber(1,address.m_address_id);
    stmt->setString(2,address.m_province_name);
    stmt->setString(3,address.m_city_name);
    stmt->setString(4,address.m_street_name);
    stmt->setString(5,address.m_street_nbr);
    stmt->setString(6,address.m_detail);
    stmt->setString(7,address.m_postcode);
    }
}

