#include "DiscountTargetObject.hh"

string DiscountTargetObject::insSQL="INSERT INTO DISCOUNT_TARGET_OBJECT(DISCOUNT_EXPRESS_ID,PRICING_REF_OBJECT_ID,REPATITION_TYPE_ID)VALUES (:DISCOUNT_EXPRESS_ID,:PRICING_REF_OBJECT_ID,:REPATITION_TYPE_ID)";

void DiscountTargetObject::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void DiscountTargetObject::prepareSQL()
{
    stmt->setNumber(1,discount_target_object.m_discount_express_id);
    stmt->setNumber(2,discount_target_object.m_pricing_ref_object_id);
    stmt->setNumber(3,discount_target_object.m_repatition_type_id);
}

