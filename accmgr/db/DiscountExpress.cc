#include "DiscountExpress.hh"

string DiscountExpress::insSQL="INSERT INTO DISCOUNT_EXPRESS(DISCOUNT_EXPRESS_ID,DISCOUNT_METHOD_ID,RATABLE_RESOURCE_ID,START_REF_VALUE_ID,END_REF_VALUE_ID,PRICING_SECTION_ID,DISCOUNT_RATE_VALUE_ID,FIXED_VALUE_ID,CALC_PRIORITY)VALUES (:DISCOUNT_EXPRESS_ID,:DISCOUNT_METHOD_ID,:RATABLE_RESOURCE_ID,:START_REF_VALUE_ID,:END_REF_VALUE_ID,:PRICING_SECTION_ID,:DISCOUNT_RATE_VALUE_ID,:FIXED_VALUE_ID,:CALC_PRIORITY)";

void DiscountExpress::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void DiscountExpress::prepareSQL()
{
    stmt->setNumber(1,discount_express.m_discount_express_id);
    stmt->setNumber(2,discount_express.m_discount_method_id);
    stmt->setNumber(3,discount_express.m_ratable_resource_id);
    stmt->setNumber(4,discount_express.m_start_ref_value_id);
    stmt->setNumber(5,discount_express.m_end_ref_value_id);
    stmt->setNumber(6,discount_express.m_pricing_section_id);
    stmt->setNumber(7,discount_express.m_discount_rate_value_id);
    stmt->setNumber(8,discount_express.m_fixed_value_id);
    stmt->setNumber(9,discount_express.m_calc_priority);
}

