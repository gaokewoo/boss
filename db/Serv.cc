#include "Serv.hh"

string Serv::insSQL="INSERT INTO SERV(SERV_ID,AGREEMENT_ID,CUST_ID,PRODUCT_ID,BILLING_CYCLE_TYPE_ID,PRODUCT_FAMILY_ID,CREATE_DATE,RENT_DATE,COMPLETED_DATE,STATE,STATE_DATE,REGION_ID,BAND_ID,OPEN_TIME,BILL_START_TIME)VALUES (:SERV_ID,:AGREEMENT_ID,:CUST_ID,:PRODUCT_ID,:BILLING_CYCLE_TYPE_ID,:PRODUCT_FAMILY_ID,SYSDATE,SYSDATE,SYSDATE,:STATE,SYSDATE,:REGION_ID,:BAND_ID,SYSDATE,SYSDATE)";

void Serv::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void Serv::prepareSQL()
{
    stmt->setNumber(1,serv.m_serv_id);
    stmt->setNumber(2,serv.m_agreement_id);
    stmt->setNumber(3,serv.m_cust_id);
    stmt->setNumber(4,serv.m_product_id);
    stmt->setNumber(5,serv.m_billing_cycle_type_id);
    stmt->setNumber(6,serv.m_product_family_id);
    stmt->setString(7,serv.m_state);
    stmt->setNumber(8,serv.m_region_id);
    stmt->setNumber(9,serv.m_band_id);
}

