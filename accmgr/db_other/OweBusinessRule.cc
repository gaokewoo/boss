#include "OweBusinessRule.hh"

string OweBusinessRule::insSQL="INSERT INTO OWE_BUSINESS_RULE(REGION_CODE,CRECTRL_RULE,MIN_OWE_FEE,MAX_OWE_FEE,MIN_OWE_DAYS,MAX_OWE_DAYS,RUN_HOUR,PREPAY_FLAG,OWE_FLAG,UNBILL_FLAG,LIMIT_FLAG,BIND_FLAG,OPERATE_TIMES,INTERVALFLAG,INTERVALTIME)VALUES (:REGION_CODE,:CRECTRL_RULE,:MIN_OWE_FEE,:MAX_OWE_FEE,:MIN_OWE_DAYS,:MAX_OWE_DAYS,:RUN_HOUR,:PREPAY_FLAG,:OWE_FLAG,:UNBILL_FLAG,:LIMIT_FLAG,:BIND_FLAG,:OPERATE_TIMES,:INTERVALFLAG,:INTERVALTIME)";

void OweBusinessRule::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void OweBusinessRule::prepareSQL()
{
    stmt->setString(1,owe_business_rule.m_region_code);
    stmt->setString(2,owe_business_rule.m_crectrl_rule);
    stmt->setNumber(3,owe_business_rule.m_min_owe_fee);
    stmt->setNumber(4,owe_business_rule.m_max_owe_fee);
    stmt->setNumber(5,owe_business_rule.m_min_owe_days);
    stmt->setNumber(6,owe_business_rule.m_max_owe_days);
    stmt->setNumber(7,owe_business_rule.m_run_hour);
    stmt->setNumber(8,owe_business_rule.m_prepay_flag);
    stmt->setNumber(9,owe_business_rule.m_owe_flag);
    stmt->setNumber(10,owe_business_rule.m_unbill_flag);
    stmt->setNumber(11,owe_business_rule.m_limit_flag);
    stmt->setNumber(12,owe_business_rule.m_bind_flag);
    stmt->setNumber(13,owe_business_rule.m_operate_times);
    stmt->setNumber(14,owe_business_rule.m_intervalflag);
    stmt->setNumber(15,owe_business_rule.m_intervaltime);
}

