#include "BillFormatSelectorRule.hh"

string BillFormatSelectorRule::insSQL="INSERT INTO BILL_FORMAT_SELECTOR_RULE(RULE_CONDITION_ID,OP_CODE,REGION_ID,CONDITION_TYPE,CONDITION_VALUE,CONDITION_DESC,CONSTRAINT)VALUES (:RULE_CONDITION_ID,:OP_CODE,:REGION_ID,:CONDITION_TYPE,:CONDITION_VALUE,:CONDITION_DESC,:CONSTRAINT)";

void BillFormatSelectorRule::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void BillFormatSelectorRule::prepareSQL()
{
    stmt->setNumber(1,bill_format_selector_rule.m_rule_condition_id);
    stmt->setString(2,bill_format_selector_rule.m_op_code);
    stmt->setNumber(3,bill_format_selector_rule.m_region_id);
    stmt->setString(4,bill_format_selector_rule.m_condition_type);
    stmt->setString(5,bill_format_selector_rule.m_condition_value);
    stmt->setString(6,bill_format_selector_rule.m_condition_desc);
    stmt->setString(7,bill_format_selector_rule.m_constraint);
}

