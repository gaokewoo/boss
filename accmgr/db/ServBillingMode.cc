#include "ServBillingMode.hh"

string ServBillingMode::insSQL="INSERT INTO SERV_BILLING_MODE(SERV_ID,AGREEMENT_ID,EFF_DATE,EXP_DATE,BILLING_MODE)VALUES (:SERV_ID,:AGREEMENT_ID,SYSDATE,SYSDATE,:BILLING_MODE)";

void ServBillingMode::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void ServBillingMode::prepareSQL()
{
    stmt->setNumber(1,serv_billing_mode.m_serv_id);
    stmt->setNumber(2,serv_billing_mode.m_agreement_id);
    stmt->setString(3,serv_billing_mode.m_billing_mode);
}

