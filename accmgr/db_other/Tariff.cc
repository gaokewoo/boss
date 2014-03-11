#include "Tariff.hh"

string Tariff::insSQL="INSERT INTO TARIFF(TARIFF_ID,TARIFF_TYPE,PRICING_SECTION_ID,RESOURCE_ID,ACTION_ID,ACCT_ITEM_TYPE_ID,SUB_PRODUCT_ID,TARIFF_UNIT_ID,CALC_METHOD_ID,RATE_UNIT,FIXED_RATE_VALUE_ID,SCALED_RATE_VALUE_ID,CALC_PRIORITY,BELONG_CYCLE_DURATION,CHARGE_PARTY_ID)VALUES (:TARIFF_ID,:TARIFF_TYPE,:PRICING_SECTION_ID,:RESOURCE_ID,:ACTION_ID,:ACCT_ITEM_TYPE_ID,:SUB_PRODUCT_ID,:TARIFF_UNIT_ID,:CALC_METHOD_ID,:RATE_UNIT,:FIXED_RATE_VALUE_ID,:SCALED_RATE_VALUE_ID,:CALC_PRIORITY,:BELONG_CYCLE_DURATION,:CHARGE_PARTY_ID)";

void Tariff::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void Tariff::prepareSQL()
{
    stmt->setNumber(1,tariff.m_tariff_id);
    stmt->setString(2,tariff.m_tariff_type);
    stmt->setNumber(3,tariff.m_pricing_section_id);
    stmt->setNumber(4,tariff.m_resource_id);
    stmt->setNumber(5,tariff.m_action_id);
    stmt->setNumber(6,tariff.m_acct_item_type_id);
    stmt->setNumber(7,tariff.m_sub_product_id);
    stmt->setNumber(8,tariff.m_tariff_unit_id);
    stmt->setNumber(9,tariff.m_calc_method_id);
    stmt->setNumber(10,tariff.m_rate_unit);
    stmt->setNumber(11,tariff.m_fixed_rate_value_id);
    stmt->setNumber(12,tariff.m_scaled_rate_value_id);
    stmt->setNumber(13,tariff.m_calc_priority);
    stmt->setNumber(14,tariff.m_belong_cycle_duration);
    stmt->setString(15,tariff.m_charge_party_id);
}

