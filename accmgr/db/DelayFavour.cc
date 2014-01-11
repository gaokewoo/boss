#include "DelayFavour.hh"

string DelayFavour::insSQL="INSERT INTO DELAY_FAVOUR(DELAY_FAV_ID,ACCT_ID,SERV_ID,YEAR_MONTH,DELAY_FEE,FAVOUR_FEE,FAVOUR_RATE,FAVOUR_TYPE,TOTAL_DATE,STAFF_ID,REGION_ID,VALIDITY_DATE,AUDIT_FLAG)VALUES (:DELAY_FAV_ID,:ACCT_ID,:SERV_ID,:YEAR_MONTH,:DELAY_FEE,:FAVOUR_FEE,:FAVOUR_RATE,:FAVOUR_TYPE,:TOTAL_DATE,:STAFF_ID,:REGION_ID,SYSDATE,:AUDIT_FLAG)";

void DelayFavour::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void DelayFavour::prepareSQL()
{
    stmt->setNumber(1,delay_favour.m_delay_fav_id);
    stmt->setNumber(2,delay_favour.m_acct_id);
    stmt->setNumber(3,delay_favour.m_serv_id);
    stmt->setNumber(4,delay_favour.m_year_month);
    stmt->setNumber(5,delay_favour.m_delay_fee);
    stmt->setNumber(6,delay_favour.m_favour_fee);
    stmt->setNumber(7,delay_favour.m_favour_rate);
    stmt->setString(8,delay_favour.m_favour_type);
    stmt->setNumber(9,delay_favour.m_total_date);
    stmt->setNumber(10,delay_favour.m_staff_id);
    stmt->setNumber(11,delay_favour.m_region_id);
    stmt->setString(12,delay_favour.m_audit_flag);
}

