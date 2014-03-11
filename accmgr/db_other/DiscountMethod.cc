#include "DiscountMethod.hh"

string DiscountMethod::insSQL="INSERT INTO DISCOUNT_METHOD(DISCOUNT_METHOD_ID,DISCOUNT_METHOD_NAME)VALUES (:DISCOUNT_METHOD_ID,:DISCOUNT_METHOD_NAME)";

void DiscountMethod::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void DiscountMethod::prepareSQL()
{
    stmt->setNumber(1,discount_method.m_discount_method_id);
    stmt->setString(2,discount_method.m_discount_method_name);
}

