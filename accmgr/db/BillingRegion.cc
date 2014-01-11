#include "BillingRegion.hh"

string BillingRegion::insSQL="INSERT INTO BILLING_REGION(REGION_ID,PARENT_REGION_ID,PARENT_REGION_LEVEL,REGION_LEVEL,REGION_CODE,DISTRICT_NUM,INTER_REGION_CODE)VALUES (:REGION_ID,:PARENT_REGION_ID,:PARENT_REGION_LEVEL,:REGION_LEVEL,:REGION_CODE,:DISTRICT_NUM,:INTER_REGION_CODE)";

void BillingRegion::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void BillingRegion::prepareSQL()
{
    stmt->setNumber(1,billing_region.m_region_id);
    stmt->setNumber(2,billing_region.m_parent_region_id);
    stmt->setString(3,billing_region.m_parent_region_level);
    stmt->setString(4,billing_region.m_region_level);
    stmt->setString(5,billing_region.m_region_code);
    stmt->setString(6,billing_region.m_district_num);
    stmt->setString(7,billing_region.m_inter_region_code);
}

