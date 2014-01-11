#include "PricingCombine.hh"

string PricingCombine::insSQL="INSERT INTO PRICING_COMBINE(PRICING_COMBINE_ID,PRICING_PLAN_ID,EVENT_PRICING_STRATEGY_ID,LIFE_CYCLE_ID,OFFER_OBJECT_ID,CALC_PRIORITY)VALUES (:PRICING_COMBINE_ID,:PRICING_PLAN_ID,:EVENT_PRICING_STRATEGY_ID,:LIFE_CYCLE_ID,:OFFER_OBJECT_ID,:CALC_PRIORITY)";

void PricingCombine::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void PricingCombine::prepareSQL()
{
    stmt->setNumber(1,pricing_combine.m_pricing_combine_id);
    stmt->setNumber(2,pricing_combine.m_pricing_plan_id);
    stmt->setNumber(3,pricing_combine.m_event_pricing_strategy_id);
    stmt->setNumber(4,pricing_combine.m_life_cycle_id);
    stmt->setNumber(5,pricing_combine.m_offer_object_id);
    stmt->setNumber(6,pricing_combine.m_calc_priority);
}

