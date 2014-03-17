#include "FavourPresentRule.hh"

string FavourPresentRule::insSQL="INSERT INTO FAVOUR_PRESENT_RULE(PRESENT_RULE_ID,REGION_ID,BAND_ID,PAY_BALANCE_TYPE_ID,AMOUNT,PRESENT_CODE,PRESENT_NAME,PRESENT_TYPE,PRESENT_MONEY,PRESENT_MONTH,CONTINUE_FLAG,CONTINUE_MONTH,ACCT_ITEM_GROUP_ID,PRESENT_RATE,DELAY_MONTH,PRESENT_COUNT,EFF_DATE,EXP_DATE,STATE,STATE_DATE,PRESENT_RULE_DESC)VALUES (:PRESENT_RULE_ID,:REGION_ID,:BAND_ID,:PAY_BALANCE_TYPE_ID,:AMOUNT,:PRESENT_CODE,:PRESENT_NAME,:PRESENT_TYPE,:PRESENT_MONEY,:PRESENT_MONTH,:CONTINUE_FLAG,:CONTINUE_MONTH,:ACCT_ITEM_GROUP_ID,:PRESENT_RATE,:DELAY_MONTH,:PRESENT_COUNT,SYSDATE,SYSDATE,:STATE,SYSDATE,:PRESENT_RULE_DESC)";

void FavourPresentRule::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void FavourPresentRule::prepareSQL()
{
    stmt->setNumber(1,favour_present_rule.m_present_rule_id);
    stmt->setNumber(2,favour_present_rule.m_region_id);
    stmt->setNumber(3,favour_present_rule.m_band_id);
    stmt->setNumber(4,favour_present_rule.m_pay_balance_type_id);
    stmt->setNumber(5,favour_present_rule.m_amount);
    stmt->setString(6,favour_present_rule.m_present_code);
    stmt->setString(7,favour_present_rule.m_present_name);
    stmt->setString(8,favour_present_rule.m_present_type);
    stmt->setNumber(9,favour_present_rule.m_present_money);
    stmt->setNumber(10,favour_present_rule.m_present_month);
    stmt->setString(11,favour_present_rule.m_continue_flag);
    stmt->setNumber(12,favour_present_rule.m_continue_month);
    stmt->setNumber(13,favour_present_rule.m_acct_item_group_id);
    stmt->setNumber(14,favour_present_rule.m_present_rate);
    stmt->setNumber(15,favour_present_rule.m_delay_month);
    stmt->setNumber(16,favour_present_rule.m_present_count);
    stmt->setString(17,favour_present_rule.m_state);
    stmt->setString(18,favour_present_rule.m_present_rule_desc);
}

