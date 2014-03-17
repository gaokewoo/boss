#include "EventPricingStrategy.hh"

string EventPricingStrategy::insSQL="INSERT INTO EVENT_PRICING_STRATEGY(EVENT_PRICING_STRATEGY_ID,EVENT_TYPE_ID,EVENT_PRICING_STRATEGY_NAME,EVENT_PRICING_STRATEGY_DESC,EVENT_PRICING_FEETYPES,EVENT_PRICING_BILLTYPE,VPNFLAG)VALUES (:EVENT_PRICING_STRATEGY_ID,:EVENT_TYPE_ID,:EVENT_PRICING_STRATEGY_NAME,:EVENT_PRICING_STRATEGY_DESC,:EVENT_PRICING_FEETYPES,:EVENT_PRICING_BILLTYPE,:VPNFLAG)";

void EventPricingStrategy::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void EventPricingStrategy::prepareSQL()
{
    stmt->setNumber(1,event_pricing_strategy.m_event_pricing_strategy_id);
    stmt->setNumber(2,event_pricing_strategy.m_event_type_id);
    stmt->setString(3,event_pricing_strategy.m_event_pricing_strategy_name);
    stmt->setString(4,event_pricing_strategy.m_event_pricing_strategy_desc);
    stmt->setString(5,event_pricing_strategy.m_event_pricing_feetypes);
    stmt->setString(6,event_pricing_strategy.m_event_pricing_billtype);
    stmt->setString(7,event_pricing_strategy.m_vpnflag);
}

