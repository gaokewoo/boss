#include "CustIdentification.hh"

string CustIdentification::insSQL="INSERT INTO CUST_IDENTIFICATION(CUST_ID,AGREEMENT_ID,CERTIFICATE_TYPE,CERTIFICATE_NO,EFF_DATE,EXP_DATE,ATTEST_TYPE,ATTEST_PASSWD,SECRECY_LEVEL)VALUES (:CUST_ID,:AGREEMENT_ID,:CERTIFICATE_TYPE,:CERTIFICATE_NO,SYSDATE,SYSDATE+365,:ATTEST_TYPE,:ATTEST_PASSWD,:SECRECY_LEVEL)";

void CustIdentification::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void CustIdentification::prepareSQL()
{
    stmt->setNumber(1,cust_identification.m_cust_id);
    stmt->setNumber(2,cust_identification.m_agreement_id);
    stmt->setString(3,cust_identification.m_certificate_type);
    stmt->setString(4,cust_identification.m_certificate_no);
    stmt->setString(5,cust_identification.m_attest_type);
    stmt->setString(6,cust_identification.m_attest_passwd);
    stmt->setString(7,cust_identification.m_secrecy_level);
}

