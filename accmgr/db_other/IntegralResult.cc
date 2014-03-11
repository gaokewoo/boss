#include "IntegralResult.hh"

string IntegralResult::insSQL="INSERT INTO INTEGRAL_RESULT(INTEGRAL_REAULT_ID,OBJECT_TYPE,OBJECT_ID,CURRENT_INTEGRAL_VALUE,ACC_AMOUNT,PRESENT_VALUE,EXCEPTION_AMOUNT)VALUES (:INTEGRAL_REAULT_ID,:OBJECT_TYPE,:OBJECT_ID,:CURRENT_INTEGRAL_VALUE,:ACC_AMOUNT,:PRESENT_VALUE,:EXCEPTION_AMOUNT)";

void IntegralResult::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void IntegralResult::prepareSQL()
{
    stmt->setNumber(1,integral_result.m_integral_reault_id);
    stmt->setString(2,integral_result.m_object_type);
    stmt->setNumber(3,integral_result.m_object_id);
    stmt->setNumber(4,integral_result.m_current_integral_value);
    stmt->setNumber(5,integral_result.m_acc_amount);
    stmt->setNumber(6,integral_result.m_present_value);
    stmt->setNumber(7,integral_result.m_exception_amount);
}

