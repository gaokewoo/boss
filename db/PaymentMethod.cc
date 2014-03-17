#include "PaymentMethod.hh"

string PaymentMethod::insSQL="INSERT INTO PAYMENT_METHOD(PAYMENT_METHOD,PAYMENT_METHOD_NAME,BALANCE_TYPE_ID)VALUES (:PAYMENT_METHOD,:PAYMENT_METHOD_NAME,:BALANCE_TYPE_ID)";

string PaymentMethod::emptySQL="DELETE FROM PAYMENT_METHOD";

string PaymentMethod::selectAllSQL="SELECT PAYMENT_METHOD,PAYMENT_METHOD_NAME,BALANCE_TYPE_ID FROM PAYMENT_METHOD";

void PaymentMethod::insertData()
{
    type=0;
    setSQL(insSQL);
    executeUpdate();
}

void PaymentMethod::emptyData()
{
    type=1;
    setSQL(emptySQL);
    executeUpdate();
}

vector<ST_PAYMENT_METHOD> PaymentMethod::loadAllData()
{
    type=2;
    setSQL(selectAllSQL);
    executeQuery();

    return v_data;
}

void PaymentMethod::doParse()
{
    payment_method.m_payment_method = (long)rset->getNumber(1);
    payment_method.m_payment_method_name = rset->getString(2);
    payment_method.m_balance_type_id = (long)rset->getNumber(3);

    v_data.push_back(payment_method);
}

void PaymentMethod::prepareSQL()
{
    if (type == 0)
    {
        stmt->setNumber(1,payment_method.m_payment_method);
        stmt->setString(2,payment_method.m_payment_method_name);
        stmt->setNumber(3,payment_method.m_balance_type_id);
    }
}

