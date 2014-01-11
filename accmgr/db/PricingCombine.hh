#ifndef __PRICINGCOMBINE__
#define __PRICINGCOMBINE__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class PricingCombine:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_PRICING_COMBINE pricing_combine;

private:
    static string insSQL;
};
#endif
