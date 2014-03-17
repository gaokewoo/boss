#include "OweDatetypeInfo.hh"

string OweDatetypeInfo::insSQL="INSERT INTO OWE_DATETYPE_INFO(OWE_TIME_INFO_ID,DATE_TYPE_ID,BILLING_CYCLE_ID,REGION_ID,DATE)VALUES (:OWE_TIME_INFO_ID,:DATE_TYPE_ID,:BILLING_CYCLE_ID,:REGION_ID,SYSDATE)";

void OweDatetypeInfo::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void OweDatetypeInfo::prepareSQL()
{
    stmt->setNumber(1,owe_datetype_info.m_owe_time_info_id);
    stmt->setNumber(2,owe_datetype_info.m_date_type_id);
    stmt->setNumber(3,owe_datetype_info.m_billing_cycle_id);
    stmt->setNumber(4,owe_datetype_info.m_region_id);
}

