#include "AcctDead.hh"

string AcctDead::insSQL="INSERT INTO ACCT_DEAD(ACCT_ID,CUST_ID,ACCT_NAME,ADDRESS_ID,STATE,STATE_DATE,ACCT_PWD,REGION_ID,ACCT_TYPE,OWE_MIN_YM,OWE_FEE,DEAD_TIME,DEAD_STAFF_ID,DEAD_OPTSN)VALUES (:ACCT_ID,:CUST_ID,:ACCT_NAME,:ADDRESS_ID,:STATE,SYSDATE,:ACCT_PWD,:REGION_ID,:ACCT_TYPE,:OWE_MIN_YM,:OWE_FEE,SYSDATE,:DEAD_STAFF_ID,:DEAD_OPTSN)";

void AcctDead::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void AcctDead::prepareSQL()
{
    stmt->setNumber(1,acct_dead.m_acct_id);
    stmt->setNumber(2,acct_dead.m_cust_id);
    stmt->setString(3,acct_dead.m_acct_name);
    stmt->setNumber(4,acct_dead.m_address_id);
    stmt->setString(5,acct_dead.m_state);
    stmt->setString(6,acct_dead.m_acct_pwd);
    stmt->setNumber(7,acct_dead.m_region_id);
    stmt->setString(8,acct_dead.m_acct_type);
    stmt->setNumber(9,acct_dead.m_owe_min_ym);
    stmt->setNumber(10,acct_dead.m_owe_fee);
    stmt->setNumber(11,acct_dead.m_dead_staff_id);
    stmt->setNumber(12,acct_dead.m_dead_optsn);
}

