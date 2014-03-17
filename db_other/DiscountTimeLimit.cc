#include "DiscountTimeLimit.hh"

string DiscountTimeLimit::insSQL="INSERT INTO DISCOUNT_TIME_LIMIT(DISCOUNT_TIME_LIMIT_ID,DISCOUNT_EXPRESS_ID,DISCOUNT_CYCLE_TYPE,BEGIN_TIME_TYPE,BEGIN_CALC_OBJECT,BEGIN_TIME_DURATION,END_TIME_TYPE,END_CALC_OBJECT,END_TIME_DURATION)VALUES (:DISCOUNT_TIME_LIMIT_ID,:DISCOUNT_EXPRESS_ID,:DISCOUNT_CYCLE_TYPE,:BEGIN_TIME_TYPE,:BEGIN_CALC_OBJECT,:BEGIN_TIME_DURATION,:END_TIME_TYPE,:END_CALC_OBJECT,:END_TIME_DURATION)";

void DiscountTimeLimit::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void DiscountTimeLimit::prepareSQL()
{
    stmt->setNumber(1,discount_time_limit.m_discount_time_limit_id);
    stmt->setNumber(2,discount_time_limit.m_discount_express_id);
    stmt->setString(3,discount_time_limit.m_discount_cycle_type);
    stmt->setString(4,discount_time_limit.m_begin_time_type);
    stmt->setNumber(5,discount_time_limit.m_begin_calc_object);
    stmt->setNumber(6,discount_time_limit.m_begin_time_duration);
    stmt->setString(7,discount_time_limit.m_end_time_type);
    stmt->setNumber(8,discount_time_limit.m_end_calc_object);
    stmt->setNumber(9,discount_time_limit.m_end_time_duration);
}

