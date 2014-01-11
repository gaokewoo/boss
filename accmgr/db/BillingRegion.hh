#ifndef __BILLINGREGION__
#define __BILLINGREGION__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class BillingRegion:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_BILLING_REGION billing_region;

private:
    static string insSQL;
};
#endif
