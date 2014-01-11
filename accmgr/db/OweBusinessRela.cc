#include "OweBusinessRela.hh"

string OweBusinessRela::insSQL="INSERT INTO OWE_BUSINESS_RELA(REGION_CODE,PLAN_CODE,CRECTRL_RULE,CRECTRL_TYPE,CRECTRL_ORDER)VALUES (:REGION_CODE,:PLAN_CODE,:CRECTRL_RULE,:CRECTRL_TYPE,:CRECTRL_ORDER)";

void OweBusinessRela::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void OweBusinessRela::prepareSQL()
{
    stmt->setString(1,owe_business_rela.m_region_code);
    stmt->setString(2,owe_business_rela.m_plan_code);
    stmt->setString(3,owe_business_rela.m_crectrl_rule);
    stmt->setString(4,owe_business_rela.m_crectrl_type);
    stmt->setNumber(5,owe_business_rela.m_crectrl_order);
}

