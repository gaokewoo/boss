#include "ShareRuleType.hh"

string ShareRuleType::insSQL="INSERT INTO SHARE_RULE_TYPE(SHARE_RULE_TYPE_ID,SHARE_RULE_TYPE_NAME)VALUES (:SHARE_RULE_TYPE_ID,:SHARE_RULE_TYPE_NAME)";

void ShareRuleType::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void ShareRuleType::prepareSQL()
{
    stmt->setNumber(1,share_rule_type.m_share_rule_type_id);
    stmt->setString(2,share_rule_type.m_share_rule_type_name);
}

