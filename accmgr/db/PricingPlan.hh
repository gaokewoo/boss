#ifndef __PRICINGPLAN__
#define __PRICINGPLAN__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class PricingPlan:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_PRICING_PLAN pricing_plan;

private:
    static string insSQL;
};
#endif
