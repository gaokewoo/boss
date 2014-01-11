#include "Address.hh"

string Address::insSQL="INSERT INTO ADDRESS(ADDRESS_ID,PROVINCE_NAME,CITY_NAME,STREET_NAME,STREET_NBR,DETAIL,POSTCODE)VALUES (:ADDRESS_ID,:PROVINCE_NAME,:CITY_NAME,:STREET_NAME,:STREET_NBR,:DETAIL,:POSTCODE)";

void Address::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void Address::prepareSQL()
{
    stmt->setNumber(1,address.m_address_id);
    stmt->setString(2,address.m_province_name);
    stmt->setString(3,address.m_city_name);
    stmt->setString(4,address.m_street_name);
    stmt->setString(5,address.m_street_nbr);
    stmt->setString(6,address.m_detail);
    stmt->setString(7,address.m_postcode);
}

