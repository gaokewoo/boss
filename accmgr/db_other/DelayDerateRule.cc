#include "DelayDerateRule.hh"

string DelayDerateRule::insSQL="INSERT INTO DELAY_DERATE_RULE(DERATE_RULE_ID,RULE_DESC,REGION_ID,DERATE_OBJECT_TYPE,DERATE_OBJECT_VALUE,DERATE_TYPE,DERATE_FEE)VALUES (:DERATE_RULE_ID,:RULE_DESC,:REGION_ID,:DERATE_OBJECT_TYPE,:DERATE_OBJECT_VALUE,:DERATE_TYPE,:DERATE_FEE)";

void DelayDerateRule::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void DelayDerateRule::prepareSQL()
{
    stmt->setNumber(1,delay_derate_rule.m_derate_rule_id);
    stmt->setString(2,delay_derate_rule.m_rule_desc);
    stmt->setNumber(3,delay_derate_rule.m_region_id);
    stmt->setString(4,delay_derate_rule.m_derate_object_type);
    stmt->setString(5,delay_derate_rule.m_derate_object_value);
    stmt->setString(6,delay_derate_rule.m_derate_type);
    stmt->setNumber(7,delay_derate_rule.m_derate_fee);
}

