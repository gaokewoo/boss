#include "BillingRegion.hh"

string BillingRegion::insSQL="INSERT INTO BILLING_REGION(REGION_ID,PARENT_REGION_ID,PARENT_REGION_LEVEL,REGION_LEVEL,REGION_CODE,DISTRICT_NUM,INTER_REGION_CODE)VALUES (:REGION_ID,:PARENT_REGION_ID,:PARENT_REGION_LEVEL,:REGION_LEVEL,:REGION_CODE,:DISTRICT_NUM,:INTER_REGION_CODE)";

string BillingRegion::emptySQL="DELETE FROM BILLING_REGION";

string BillingRegion::selectAllSQL="SELECT REGION_ID,PARENT_REGION_ID,PARENT_REGION_LEVEL,REGION_LEVEL,REGION_CODE,DISTRICT_NUM,INTER_REGION_CODE FROM BILLING_REGION";

void BillingRegion::insertData()
{
    type=0;
    setSQL(insSQL);
    executeUpdate();
}

void BillingRegion::emptyData()
{
    type=1;
    setSQL(emptySQL);
    executeUpdate();
}

vector<ST_BILLING_REGION> BillingRegion::loadAllData()
{
    type=2;
    setSQL(selectAllSQL);
    executeQuery();

    return v_data;
}

void BillingRegion::doParse()
{
    billing_region.m_region_id = (long)rset->getNumber(1);
    billing_region.m_parent_region_id = (long)rset->getNumber(2);
    billing_region.m_parent_region_level = rset->getString(3);
    billing_region.m_region_level = rset->getString(4);
    billing_region.m_region_code = rset->getString(5);
    billing_region.m_district_num = rset->getString(6);
    billing_region.m_inter_region_code = rset->getString(7);

    v_data.push_back(billing_region);
}

void BillingRegion::prepareSQL()
{
    if (type == 0)
    {
    stmt->setNumber(1,billing_region.m_region_id);
    stmt->setNumber(2,billing_region.m_parent_region_id);
    stmt->setString(3,billing_region.m_parent_region_level);
    stmt->setString(4,billing_region.m_region_level);
    stmt->setString(5,billing_region.m_region_code);
    stmt->setString(6,billing_region.m_district_num);
    stmt->setString(7,billing_region.m_inter_region_code);
    }
}

