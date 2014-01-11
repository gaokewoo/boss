#include "PricingSection.hh"

string PricingSection::insSQL="INSERT INTO PRICING_SECTION(PRICING_SECTION_ID,SECTION_TYPE_ID,SECTION_CALC_TYPE,PRICING_SECTION_NAME,PARENT_SECTION_ID,PRICING_REF_OBJECT_ID,ZONE_ITEM_ID,CYCLE_SECTION_BEGIN,CYCLE_SECTION_DURATION,START_REF_VALUE_ID,END_REF_VALUE_ID,JUDGE_RESULT,EVENT_PRICING_STRATEGY_ID,CALC_PRIORITY)VALUES (:PRICING_SECTION_ID,:SECTION_TYPE_ID,:SECTION_CALC_TYPE,:PRICING_SECTION_NAME,:PARENT_SECTION_ID,:PRICING_REF_OBJECT_ID,:ZONE_ITEM_ID,:CYCLE_SECTION_BEGIN,:CYCLE_SECTION_DURATION,:START_REF_VALUE_ID,:END_REF_VALUE_ID,:JUDGE_RESULT,:EVENT_PRICING_STRATEGY_ID,:CALC_PRIORITY)";

void PricingSection::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void PricingSection::prepareSQL()
{
    stmt->setNumber(1,pricing_section.m_pricing_section_id);
    stmt->setNumber(2,pricing_section.m_section_type_id);
    stmt->setString(3,pricing_section.m_section_calc_type);
    stmt->setString(4,pricing_section.m_pricing_section_name);
    stmt->setNumber(5,pricing_section.m_parent_section_id);
    stmt->setNumber(6,pricing_section.m_pricing_ref_object_id);
    stmt->setNumber(7,pricing_section.m_zone_item_id);
    stmt->setNumber(8,pricing_section.m_cycle_section_begin);
    stmt->setNumber(9,pricing_section.m_cycle_section_duration);
    stmt->setNumber(10,pricing_section.m_start_ref_value_id);
    stmt->setNumber(11,pricing_section.m_end_ref_value_id);
    stmt->setString(12,pricing_section.m_judge_result);
    stmt->setNumber(13,pricing_section.m_event_pricing_strategy_id);
    stmt->setNumber(14,pricing_section.m_calc_priority);
}

