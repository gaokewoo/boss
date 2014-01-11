#include "DiscountRepatitionType.hh"

string DiscountRepatitionType::insSQL="INSERT INTO DISCOUNT_REPATITION_TYPE(REPATITION_TYPE_ID,REPATITION_TYPE_NAME,PRICING_REF_OBJECT_ID)VALUES (:REPATITION_TYPE_ID,:REPATITION_TYPE_NAME,:PRICING_REF_OBJECT_ID)";

void DiscountRepatitionType::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void DiscountRepatitionType::prepareSQL()
{
    stmt->setNumber(1,discount_repatition_type.m_repatition_type_id);
    stmt->setString(2,discount_repatition_type.m_repatition_type_name);
    stmt->setNumber(3,discount_repatition_type.m_pricing_ref_object_id);
}

