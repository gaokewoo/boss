#ifndef __PRICINGCOMBINERELATION__
#define __PRICINGCOMBINERELATION__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class PricingCombineRelation:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_PRICING_COMBINE_RELATION pricing_combine_relation;

private:
    static string insSQL;
};
#endif
