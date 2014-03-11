#include "BalancePresentRule.hh"

string BalancePresentRule::insSQL="INSERT INTO BALANCE_PRESENT_RULE(PRESENT_RULE_ID,PAY_BALANCE_TYPE_ID,PRESENT_BALANCE_TYPE_ID,PRESENT_RULE_DESC,REF_CEIL,REF_FLOOR,BASE_VALUE,CALC_METHOD,CALC_VALUE,CALC_RATE,CALC_PRECISION,MAX_VALUE,EFF_OFFSET_UNIT,EFF_OFFSET_VALUE,STATE,STATE_DATE,EFF_DATE,EXP_DATE,REGION_ID,BAND_ID,PRESENT_CODE,PRESENT_NAME,PRESENT_TYPE,CONTINUE_FLAG,CONTINUE_MONTH,ACCT_ITEM_GROUP_ID,DELAY_MONTH,PRESENT_COUNT)VALUES (:PRESENT_RULE_ID,:PAY_BALANCE_TYPE_ID,:PRESENT_BALANCE_TYPE_ID,:PRESENT_RULE_DESC,:REF_CEIL,:REF_FLOOR,:BASE_VALUE,:CALC_METHOD,:CALC_VALUE,:CALC_RATE,:CALC_PRECISION,:MAX_VALUE,:EFF_OFFSET_UNIT,:EFF_OFFSET_VALUE,:STATE,SYSDATE,SYSDATE,SYSDATE,:REGION_ID,:BAND_ID,:PRESENT_CODE,:PRESENT_NAME,:PRESENT_TYPE,:CONTINUE_FLAG,:CONTINUE_MONTH,:ACCT_ITEM_GROUP_ID,:DELAY_MONTH,:PRESENT_COUNT)";

void BalancePresentRule::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void BalancePresentRule::prepareSQL()
{
    stmt->setNumber(1,balance_present_rule.m_present_rule_id);
    stmt->setNumber(2,balance_present_rule.m_pay_balance_type_id);
    stmt->setNumber(3,balance_present_rule.m_present_balance_type_id);
    stmt->setString(4,balance_present_rule.m_present_rule_desc);
    stmt->setNumber(5,balance_present_rule.m_ref_ceil);
    stmt->setNumber(6,balance_present_rule.m_ref_floor);
    stmt->setNumber(7,balance_present_rule.m_base_value);
    stmt->setString(8,balance_present_rule.m_calc_method);
    stmt->setNumber(9,balance_present_rule.m_calc_value);
    stmt->setNumber(10,balance_present_rule.m_calc_rate);
    stmt->setNumber(11,balance_present_rule.m_calc_precision);
    stmt->setNumber(12,balance_present_rule.m_max_value);
    stmt->setString(13,balance_present_rule.m_eff_offset_unit);
    stmt->setNumber(14,balance_present_rule.m_eff_offset_value);
    stmt->setString(15,balance_present_rule.m_state);
    stmt->setNumber(16,balance_present_rule.m_region_id);
    stmt->setNumber(17,balance_present_rule.m_band_id);
    stmt->setString(18,balance_present_rule.m_present_code);
    stmt->setString(19,balance_present_rule.m_present_name);
    stmt->setString(20,balance_present_rule.m_present_type);
    stmt->setString(21,balance_present_rule.m_continue_flag);
    stmt->setNumber(22,balance_present_rule.m_continue_month);
    stmt->setNumber(23,balance_present_rule.m_acct_item_group_id);
    stmt->setNumber(24,balance_present_rule.m_delay_month);
    stmt->setNumber(25,balance_present_rule.m_present_count);
}

