#include "CreditGrade.hh"

string CreditGrade::insSQL="INSERT INTO CREDIT_GRADE(CREDIT_GRADE_ID,CREDIT_GRADE_NAME)VALUES (:CREDIT_GRADE_ID,:CREDIT_GRADE_NAME)";

void CreditGrade::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void CreditGrade::prepareSQL()
{
    stmt->setNumber(1,credit_grade.m_credit_grade_id);
    stmt->setString(2,credit_grade.m_credit_grade_name);
}

