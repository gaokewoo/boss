#include "AcctCredit.hh"

string AcctCredit::insSQL="INSERT INTO ACCT_CREDIT(ACCT_ID,CREDIT_GRADE,CREDIT_AMOUNT,EXCEPTION_AMOUNT,EFF_DATE)VALUES (:ACCT_ID,:CREDIT_GRADE,:CREDIT_AMOUNT,:EXCEPTION_AMOUNT,SYSDATE)";

void AcctCredit::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void AcctCredit::prepareSQL()
{
    stmt->setNumber(1,acct_credit.m_acct_id);
    stmt->setNumber(2,acct_credit.m_credit_grade);
    stmt->setNumber(3,acct_credit.m_credit_amount);
    stmt->setNumber(4,acct_credit.m_exception_amount);
}

