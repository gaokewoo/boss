#include "ServBillingModeDead.hh"

string ServBillingModeDead::insSQL="INSERT INTO SERV_BILLING_MODE_DEAD(SERV_ID,AGREEMENT_ID,EFF_DATE,EXP_DATE,BILLING_MODE,DEAD_TIME,DEAD_STAFF_ID,DEAD_OPTSN)VALUES (:SERV_ID,:AGREEMENT_ID,SYSDATE,SYSDATE,:BILLING_MODE,SYSDATE,:DEAD_STAFF_ID,:DEAD_OPTSN)";

void ServBillingModeDead::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void ServBillingModeDead::prepareSQL()
{
    stmt->setNumber(1,serv_billing_mode_dead.m_serv_id);
    stmt->setNumber(2,serv_billing_mode_dead.m_agreement_id);
    stmt->setString(3,serv_billing_mode_dead.m_billing_mode);
    stmt->setNumber(4,serv_billing_mode_dead.m_dead_staff_id);
    stmt->setNumber(5,serv_billing_mode_dead.m_dead_optsn);
}

