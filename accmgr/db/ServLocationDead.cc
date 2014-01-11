#include "ServLocationDead.hh"

string ServLocationDead::insSQL="INSERT INTO SERV_LOCATION_DEAD(SERV_ID,AGREEMENT_ID,ADDRESS_ID,BUREAU_ID,EXCHANGE_ID,STAT_REGION_ID,EFF_DATE,EXP_DATE,DEAD_TIME,DEAD_STAFF_ID,DEAD_OPTSN)VALUES (:SERV_ID,:AGREEMENT_ID,:ADDRESS_ID,:BUREAU_ID,:EXCHANGE_ID,:STAT_REGION_ID,SYSDATE,SYSDATE,SYSDATE,:DEAD_STAFF_ID,:DEAD_OPTSN)";

void ServLocationDead::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void ServLocationDead::prepareSQL()
{
    stmt->setNumber(1,serv_location_dead.m_serv_id);
    stmt->setNumber(2,serv_location_dead.m_agreement_id);
    stmt->setNumber(3,serv_location_dead.m_address_id);
    stmt->setNumber(4,serv_location_dead.m_bureau_id);
    stmt->setNumber(5,serv_location_dead.m_exchange_id);
    stmt->setNumber(6,serv_location_dead.m_stat_region_id);
    stmt->setNumber(7,serv_location_dead.m_dead_staff_id);
    stmt->setNumber(8,serv_location_dead.m_dead_optsn);
}

