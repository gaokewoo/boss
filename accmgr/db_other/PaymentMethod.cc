#include "PaymentMethod.hh"

string PaymentMethod::insSQL="INSERT INTO PAYMENT_METHOD(PAYMENT_METHOD,PAYMENT_METHOD_NAME,BALANCE_TYPE_ID)VALUES (:PAYMENT_METHOD,:PAYMENT_METHOD_NAME,:BALANCE_TYPE_ID)";

void PaymentMethod::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void PaymentMethod::prepareSQL()
{
    stmt->setNumber(1,payment_method.m_payment_method);
    stmt->setString(2,payment_method.m_payment_method_name);
    stmt->setNumber(3,payment_method.m_balance_type_id);
}

