#include "PricingRule.hh"

string PricingRule::insSQL="INSERT INTO PRICING_RULE(PRICING_RULE_ID,PRICING_SECTION_ID,PRICING_REF_OBJECT_ID,OPERATOR_ID,RESULT_REF_VALUE_ID,GROUP_ID)VALUES (:PRICING_RULE_ID,:PRICING_SECTION_ID,:PRICING_REF_OBJECT_ID,:OPERATOR_ID,:RESULT_REF_VALUE_ID,:GROUP_ID)";

void PricingRule::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void PricingRule::prepareSQL()
{
    stmt->setNumber(1,pricing_rule.m_pricing_rule_id);
    stmt->setNumber(2,pricing_rule.m_pricing_section_id);
    stmt->setNumber(3,pricing_rule.m_pricing_ref_object_id);
    stmt->setNumber(4,pricing_rule.m_operator_id);
    stmt->setNumber(5,pricing_rule.m_result_ref_value_id);
    stmt->setNumber(6,pricing_rule.m_group_id);
}

