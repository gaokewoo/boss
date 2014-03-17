#ifndef __PRICINGENUMPARAM__
#define __PRICINGENUMPARAM__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class PricingEnumParam:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_PRICING_ENUM_PARAM pricing_enum_param;

private:
    static string insSQL;
};
#endif
