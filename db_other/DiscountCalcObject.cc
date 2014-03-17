#include "DiscountCalcObject.hh"

string DiscountCalcObject::insSQL="INSERT INTO DISCOUNT_CALC_OBJECT(DISCONT_EXPRESS_ID,PRICING_REF_OBJECT_ID)VALUES (:DISCONT_EXPRESS_ID,:PRICING_REF_OBJECT_ID)";

void DiscountCalcObject::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void DiscountCalcObject::prepareSQL()
{
    stmt->setNumber(1,discount_calc_object.m_discont_express_id);
    stmt->setNumber(2,discount_calc_object.m_pricing_ref_object_id);
}

