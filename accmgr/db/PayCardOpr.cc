#include "PayCardOpr.hh"

string PayCardOpr::insSQL="INSERT INTO PAY_CARD_OPR(PAYMENT_ID,CARD_TYPE,CARD_NBR,CARD_FEE)VALUES (:PAYMENT_ID,:CARD_TYPE,:CARD_NBR,:CARD_FEE)";

void PayCardOpr::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void PayCardOpr::prepareSQL()
{
    stmt->setNumber(1,pay_card_opr.m_payment_id);
    stmt->setString(2,pay_card_opr.m_card_type);
    stmt->setString(3,pay_card_opr.m_card_nbr);
    stmt->setNumber(4,pay_card_opr.m_card_fee);
}

