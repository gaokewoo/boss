#ifndef __PRICINGRULE__
#define __PRICINGRULE__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class PricingRule:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_PRICING_RULE pricing_rule;

private:
    static string insSQL;
};
#endif
