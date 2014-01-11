#include "ProductOfferObject.hh"

string ProductOfferObject::insSQL="INSERT INTO PRODUCT_OFFER_OBJECT(OFFER_OBJECT_ID,OFFER_ID,OBJECT_TYPE,OBJECT_ID,OBJECT_AMOUNT_START,OBJECT_AMOUNT_END,PRIORITY)VALUES (:OFFER_OBJECT_ID,:OFFER_ID,:OBJECT_TYPE,:OBJECT_ID,:OBJECT_AMOUNT_START,:OBJECT_AMOUNT_END,:PRIORITY)";

void ProductOfferObject::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void ProductOfferObject::prepareSQL()
{
    stmt->setNumber(1,product_offer_object.m_offer_object_id);
    stmt->setNumber(2,product_offer_object.m_offer_id);
    stmt->setString(3,product_offer_object.m_object_type);
    stmt->setNumber(4,product_offer_object.m_object_id);
    stmt->setNumber(5,product_offer_object.m_object_amount_start);
    stmt->setNumber(6,product_offer_object.m_object_amount_end);
    stmt->setNumber(7,product_offer_object.m_priority);
}

