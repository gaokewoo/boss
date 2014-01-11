#ifndef __EVENTPRICINGSTRATEGY__
#define __EVENTPRICINGSTRATEGY__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class EventPricingStrategy:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_EVENT_PRICING_STRATEGY event_pricing_strategy;

private:
    static string insSQL;
};
#endif
