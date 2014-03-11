#ifndef __PRICINGPARAMDEFINE__
#define __PRICINGPARAMDEFINE__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class PricingParamDefine:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_PRICING_PARAM_DEFINE pricing_param_define;

private:
    static string insSQL;
};
#endif
