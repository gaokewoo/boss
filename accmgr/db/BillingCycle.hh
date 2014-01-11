#ifndef __BILLINGCYCLE__
#define __BILLINGCYCLE__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class BillingCycle:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_BILLING_CYCLE billing_cycle;

private:
    static string insSQL;
};
#endif
