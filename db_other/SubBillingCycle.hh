#ifndef __SUBBILLINGCYCLE__
#define __SUBBILLINGCYCLE__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class SubBillingCycle:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_SUB_BILLING_CYCLE sub_billing_cycle;

private:
    static string insSQL;
};
#endif
