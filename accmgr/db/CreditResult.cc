#include "CreditResult.hh"

string CreditResult::insSQL="INSERT INTO CREDIT_RESULT(CREDIT_RESULT_ID,CREDIT_GRADE_ID,OBJECT_TYPE,OBJECT_ID,CREDIT_AMOUNT,EXCEPTION_AMOUNT,EFF_DATE)VALUES (:CREDIT_RESULT_ID,:CREDIT_GRADE_ID,:OBJECT_TYPE,:OBJECT_ID,:CREDIT_AMOUNT,:EXCEPTION_AMOUNT,SYSDATE)";

void CreditResult::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void CreditResult::prepareSQL()
{
    stmt->setNumber(1,credit_result.m_credit_result_id);
    stmt->setNumber(2,credit_result.m_credit_grade_id);
    stmt->setString(3,credit_result.m_object_type);
    stmt->setNumber(4,credit_result.m_object_id);
    stmt->setNumber(5,credit_result.m_credit_amount);
    stmt->setNumber(6,credit_result.m_exception_amount);
}

