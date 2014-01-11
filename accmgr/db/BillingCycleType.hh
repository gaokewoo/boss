#ifndef __BILLINGCYCLETYPE__
#define __BILLINGCYCLETYPE__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class BillingCycleType:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_BILLING_CYCLE_TYPE billing_cycle_type;

private:
    static string insSQL;
};
#endif
