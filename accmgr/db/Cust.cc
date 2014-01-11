#include "Cust.hh"

string Cust::insSQL="INSERT INTO CUST(CUST_ID,PARTY_ROLE_ID,CUST_NAME,CUST_TYPE,CUST_LOCATION,IS_VIP,PARENT_ID,CUST_CODE,STATE,EFF_DATE,EXP_DATE)VALUES (:CUST_ID,:PARTY_ROLE_ID,:CUST_NAME,:CUST_TYPE,:CUST_LOCATION,:IS_VIP,:PARENT_ID,:CUST_CODE,:STATE,SYSDATE,SYSDATE)";

void Cust::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void Cust::prepareSQL()
{
    stmt->setNumber(1,cust.m_cust_id);
    stmt->setNumber(2,cust.m_party_role_id);
    stmt->setString(3,cust.m_cust_name);
    stmt->setString(4,cust.m_cust_type);
    stmt->setNumber(5,cust.m_cust_location);
    stmt->setString(6,cust.m_is_vip);
    stmt->setNumber(7,cust.m_parent_id);
    stmt->setString(8,cust.m_cust_code);
    stmt->setString(9,cust.m_state);
}

