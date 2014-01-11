#include "PaymentRule.hh"

string PaymentRule::insSQL="INSERT INTO PAYMENT_RULE(PAYMENT_RULE_ID,CUST_AGREEMENT_ID,NAME,COMMENTS)VALUES (:PAYMENT_RULE_ID,:CUST_AGREEMENT_ID,:NAME,:COMMENTS)";

void PaymentRule::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void PaymentRule::prepareSQL()
{
    stmt->setNumber(1,payment_rule.m_payment_rule_id);
    stmt->setNumber(2,payment_rule.m_cust_agreement_id);
    stmt->setString(3,payment_rule.m_name);
    stmt->setString(4,payment_rule.m_comments);
}

