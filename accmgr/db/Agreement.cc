#include "Agreement.hh"

string Agreement::insSQL="INSERT INTO AGREEMENT(AGREEMENT_ID,CUST_ID,AGREEMENT_TYPE,SIGN_DATE,COMPLETED_DATE,ACCEPT_STAFF_ID,STATE,COMMENTS)VALUES (:AGREEMENT_ID,:CUST_ID,:AGREEMENT_TYPE,SYSDATE,SYSDATE,:ACCEPT_STAFF_ID,:STATE,:COMMENTS)";

void Agreement::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void Agreement::prepareSQL()
{
    stmt->setNumber(1,agreement.m_agreement_id);
    stmt->setNumber(2,agreement.m_cust_id);
    stmt->setString(3,agreement.m_agreement_type);
    stmt->setNumber(4,agreement.m_accept_staff_id);
    stmt->setString(5,agreement.m_state);
    stmt->setString(6,agreement.m_comments);
}

