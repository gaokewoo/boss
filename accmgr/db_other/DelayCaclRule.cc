#include "DelayCaclRule.hh"

string DelayCaclRule::insSQL="INSERT INTO DELAY_CACL_RULE(DELAY_RULE_ID,RULE_DESC,OWE_DUE_MONTHS,OWE_DUE_DAYS,OWE_UPPER_DAYS,OWE_STEP_FEE,CALC_RATE,MAX_DELAY_FEE,OBJECT_TYPE,OBJECT_VALUE,REGION_ID)VALUES (:DELAY_RULE_ID,:RULE_DESC,:OWE_DUE_MONTHS,:OWE_DUE_DAYS,:OWE_UPPER_DAYS,:OWE_STEP_FEE,:CALC_RATE,:MAX_DELAY_FEE,:OBJECT_TYPE,:OBJECT_VALUE,:REGION_ID)";

void DelayCaclRule::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void DelayCaclRule::prepareSQL()
{
    stmt->setNumber(1,delay_cacl_rule.m_delay_rule_id);
    stmt->setString(2,delay_cacl_rule.m_rule_desc);
    stmt->setNumber(3,delay_cacl_rule.m_owe_due_months);
    stmt->setNumber(4,delay_cacl_rule.m_owe_due_days);
    stmt->setNumber(5,delay_cacl_rule.m_owe_upper_days);
    stmt->setNumber(6,delay_cacl_rule.m_owe_step_fee);
    stmt->setNumber(7,delay_cacl_rule.m_calc_rate);
    stmt->setNumber(8,delay_cacl_rule.m_max_delay_fee);
    stmt->setString(9,delay_cacl_rule.m_object_type);
    stmt->setString(10,delay_cacl_rule.m_object_value);
    stmt->setNumber(11,delay_cacl_rule.m_region_id);
}

