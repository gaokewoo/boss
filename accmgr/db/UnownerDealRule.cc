#include "UnownerDealRule.hh"

string UnownerDealRule::insSQL="INSERT INTO UNOWNER_DEAL_RULE(REGION_CODE,UNOWNER_TYPE,UNOWNER_DAY,UNOWNER_COUNT,UNOWNER_MONEY,STATE,STATE_DATE,RULE_DESC)VALUES (:REGION_CODE,:UNOWNER_TYPE,:UNOWNER_DAY,:UNOWNER_COUNT,:UNOWNER_MONEY,:STATE,SYSDATE,:RULE_DESC)";

void UnownerDealRule::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void UnownerDealRule::prepareSQL()
{
    stmt->setString(1,unowner_deal_rule.m_region_code);
    stmt->setString(2,unowner_deal_rule.m_unowner_type);
    stmt->setNumber(3,unowner_deal_rule.m_unowner_day);
    stmt->setNumber(4,unowner_deal_rule.m_unowner_count);
    stmt->setNumber(5,unowner_deal_rule.m_unowner_money);
    stmt->setString(6,unowner_deal_rule.m_state);
    stmt->setString(7,unowner_deal_rule.m_rule_desc);
}

