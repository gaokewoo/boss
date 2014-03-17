#include "Acct.hh"

string Acct::insSQL="INSERT INTO ACCT(ACCT_ID,CUST_ID,ACCT_NAME,ADDRESS_ID,STATE,STATE_DATE,ACCT_PWD,REGION_ID,ACCT_TYPE,OWE_MIN_YM,OWE_FEE)VALUES (:ACCT_ID,:CUST_ID,:ACCT_NAME,:ADDRESS_ID,:STATE,SYSDATE,:ACCT_PWD,:REGION_ID,:ACCT_TYPE,:OWE_MIN_YM,:OWE_FEE)";

void Acct::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void Acct::prepareSQL()
{
    stmt->setNumber(1,acct.m_acct_id);
    stmt->setNumber(2,acct.m_cust_id);
    stmt->setString(3,acct.m_acct_name);
    stmt->setNumber(4,acct.m_address_id);
    stmt->setString(5,acct.m_state);
    stmt->setString(6,acct.m_acct_pwd);
    stmt->setNumber(7,acct.m_region_id);
    stmt->setString(8,acct.m_acct_type);
    stmt->setNumber(9,acct.m_owe_min_ym);
    stmt->setNumber(10,acct.m_owe_fee);
}

