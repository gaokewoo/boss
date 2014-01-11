#ifndef __PRICINGSECTION__
#define __PRICINGSECTION__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class PricingSection:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_PRICING_SECTION pricing_section;

private:
    static string insSQL;
};
#endif
