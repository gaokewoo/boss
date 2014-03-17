#include "CustDead.hh"

string CustDead::insSQL="INSERT INTO CUST_DEAD(CUST_ID,PARTY_ROLE_ID,CUST_NAME,CUST_TYPE,CUST_LOCATION,IS_VIP,PARENT_ID,CUST_CODE,STATE,EFF_DATE,EXP_DATE,DEAD_TIME,DEAD_STAFF_ID,DEAD_OPTSN)VALUES (:CUST_ID,:PARTY_ROLE_ID,:CUST_NAME,:CUST_TYPE,:CUST_LOCATION,:IS_VIP,:PARENT_ID,:CUST_CODE,:STATE,SYSDATE,SYSDATE,SYSDATE,:DEAD_STAFF_ID,:DEAD_OPTSN)";

void CustDead::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void CustDead::prepareSQL()
{
    stmt->setNumber(1,cust_dead.m_cust_id);
    stmt->setNumber(2,cust_dead.m_party_role_id);
    stmt->setString(3,cust_dead.m_cust_name);
    stmt->setString(4,cust_dead.m_cust_type);
    stmt->setNumber(5,cust_dead.m_cust_location);
    stmt->setString(6,cust_dead.m_is_vip);
    stmt->setNumber(7,cust_dead.m_parent_id);
    stmt->setString(8,cust_dead.m_cust_code);
    stmt->setString(9,cust_dead.m_state);
    stmt->setNumber(10,cust_dead.m_dead_staff_id);
    stmt->setNumber(11,cust_dead.m_dead_optsn);
}

