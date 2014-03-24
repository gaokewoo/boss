#include "Serv.hh"

string Serv::insSQL="INSERT INTO SERV(SERV_ID,AGREEMENT_ID,CUST_ID,PRODUCT_ID,BILLING_CYCLE_TYPE_ID,PRODUCT_FAMILY_ID,CREATE_DATE,RENT_DATE,COMPLETED_DATE,STATE,STATE_DATE,REGION_ID,BAND_ID,OPEN_TIME,BILL_START_TIME)VALUES (:SERV_ID,:AGREEMENT_ID,:CUST_ID,:PRODUCT_ID,:BILLING_CYCLE_TYPE_ID,:PRODUCT_FAMILY_ID,SYSDATE,SYSDATE,SYSDATE,:STATE,SYSDATE,:REGION_ID,:BAND_ID,SYSDATE,SYSDATE)";

void Serv::insertData()
{
    type=INSERT;
    setSQL(insSQL);
    executeUpdate();
}

ST_SERV Serv::getServByServId(long serv_id)
{
    type=SELECT_BY_SERV_ID;
    m_serv_id=serv_id;
    setSQL("SELECT SERV_ID,AGREEMENT_ID,CUST_ID,PRODUCT_ID,BILLING_CYCLE_TYPE_ID,PRODUCT_FAMILY_ID,TO_CHAR(CREATE_DATE,'YYYYMMDDHH24MISS'),TO_CHAR(RENT_DATE,'YYYYMMDDHH24MISS'),TO_CHAR(COMPLETED_DATE,'YYYYMMDDHH24MISS'),STATE,TO_CHAR(STATE_DATE,'YYYYMMDDHH24MISS'),REGION_ID,BAND_ID,TO_CHAR(OPEN_TIME,'YYYYMMDDHH24MISS'),TO_CHAR(BILL_START_TIME,'YYYYMMDDHH24MISS') FROM SERV WHERE SERV_ID=:SERV_ID");
    executeQuery();

    return serv;
}

void Serv::updateStateInServByServId(long serv_id,string state)
{
    type=UPDATE;
    m_serv_id=serv_id;
    m_state=state;

    setSQL("UPDATE SERV SET STATE=:STATE, STATE_DATE=SYSDATE WHERE SERV_ID=:SERV_ID");
    executeUpdate();
}

void Serv::doParse()
{
    serv.m_serv_id = (long)rset->getNumber(1);
    serv.m_agreement_id = (long)rset->getNumber(2);
    serv.m_cust_id = (long)rset->getNumber(3);
    serv.m_product_id = (long)rset->getNumber(4);
    serv.m_billing_cycle_type_id = (long)rset->getNumber(5);
    serv.m_product_family_id = (long)rset->getNumber(6);
    serv.m_create_date = rset->getString(7);
    serv.m_rent_date = rset->getString(8);
    serv.m_completed_date = rset->getString(9);
    serv.m_state = rset->getString(10);
    serv.m_state_date = rset->getString(11);
    serv.m_region_id = (long)rset->getNumber(12);
    serv.m_band_id = (long)rset->getNumber(13);
    serv.m_open_time = rset->getString(14);
    serv.m_bill_start_time = rset->getString(15);
}

void Serv::prepareSQL()
{
    if (type == INSERT)
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
    else if (type == SELECT_BY_SERV_ID)
    {
        stmt->setNumber(1,m_serv_id);
    }
    else if (type == UPDATE)
    {
        stmt->setString(1,m_state);
        stmt->setNumber(2,m_serv_id);
    }
}

