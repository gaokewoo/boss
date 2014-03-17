#include "ServDead.hh"

string ServDead::insSQL="INSERT INTO SERV_DEAD(SERV_ID,AGREEMENT_ID,CUST_ID,PRODUCT_ID,BILLING_CYCLE_TYPE_ID,PRODUCT_FAMILY_ID,CREATE_DATE,RENT_DATE,COMPLETED_DATE,STATE,STATE_DATE,REGION_ID,BAND_ID,OPEN_TIME,BILL_START_TIME,DEAD_TIME,DEAD_STAFF_ID,DEAD_OPTSN)VALUES (:SERV_ID,:AGREEMENT_ID,:CUST_ID,:PRODUCT_ID,:BILLING_CYCLE_TYPE_ID,:PRODUCT_FAMILY_ID,SYSDATE,SYSDATE,SYSDATE,:STATE,SYSDATE,:REGION_ID,:BAND_ID,SYSDATE,SYSDATE,SYSDATE,:DEAD_STAFF_ID,:DEAD_OPTSN)";

void ServDead::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void ServDead::prepareSQL()
{
    stmt->setNumber(1,serv_dead.m_serv_id);
    stmt->setNumber(2,serv_dead.m_agreement_id);
    stmt->setNumber(3,serv_dead.m_cust_id);
    stmt->setNumber(4,serv_dead.m_product_id);
    stmt->setNumber(5,serv_dead.m_billing_cycle_type_id);
    stmt->setNumber(6,serv_dead.m_product_family_id);
    stmt->setString(7,serv_dead.m_state);
    stmt->setNumber(8,serv_dead.m_region_id);
    stmt->setNumber(9,serv_dead.m_band_id);
    stmt->setNumber(10,serv_dead.m_dead_staff_id);
    stmt->setNumber(11,serv_dead.m_dead_optsn);
}

