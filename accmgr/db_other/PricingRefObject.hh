#ifndef __PRICINGREFOBJECT__
#define __PRICINGREFOBJECT__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class PricingRefObject:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_PRICING_REF_OBJECT pricing_ref_object;

private:
    static string insSQL;
};
#endif
