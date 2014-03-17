#ifndef __BILLINGCYCLE__
#define __BILLINGCYCLE__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class BillingCycle:public SQLInterface
{
public:
    void insertData();
    void emptyData();
    vector<ST_BILLING_CYCLE> loadAllData();
    virtual void prepareSQL();
    virtual void doParse();

public:
    ST_BILLING_CYCLE billing_cycle;

private:
    int type;
    static string emptySQL;
    static string selectAllSQL;
    vector<ST_BILLING_CYCLE> v_data;
    static string insSQL;
};
#endif
