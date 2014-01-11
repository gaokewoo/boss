#include "ServStateAttr.hh"

string ServStateAttr::insSQL="INSERT INTO SERV_STATE_ATTR(SERV_ID,BILLING_CYCLE_TYPE_ID,AGREEMENT_ID,OWE_BUSINESS_TYPE_ID,STATE,EFF_DATE,EXP_DATE)VALUES (:SERV_ID,:BILLING_CYCLE_TYPE_ID,:AGREEMENT_ID,:OWE_BUSINESS_TYPE_ID,:STATE,SYSDATE,SYSDATE)";

void ServStateAttr::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void ServStateAttr::prepareSQL()
{
    stmt->setNumber(1,serv_state_attr.m_serv_id);
    stmt->setNumber(2,serv_state_attr.m_billing_cycle_type_id);
    stmt->setNumber(3,serv_state_attr.m_agreement_id);
    stmt->setNumber(4,serv_state_attr.m_owe_business_type_id);
    stmt->setString(5,serv_state_attr.m_state);
}

