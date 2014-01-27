#include "ServLocation.hh"

string ServLocation::insSQL="INSERT INTO SERV_LOCATION(SERV_ID,AGREEMENT_ID,ADDRESS_ID,BUREAU_ID,EXCHANGE_ID,STAT_REGION_ID,EFF_DATE,EXP_DATE)VALUES (:SERV_ID,:AGREEMENT_ID,:ADDRESS_ID,:BUREAU_ID,:EXCHANGE_ID,:STAT_REGION_ID,SYSDATE,SYSDATE+365)";

void ServLocation::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void ServLocation::prepareSQL()
{
    stmt->setNumber(1,serv_location.m_serv_id);
    stmt->setNumber(2,serv_location.m_agreement_id);
    stmt->setNumber(3,serv_location.m_address_id);
    stmt->setNumber(4,serv_location.m_bureau_id);
    stmt->setNumber(5,serv_location.m_exchange_id);
    stmt->setNumber(6,serv_location.m_stat_region_id);
}

