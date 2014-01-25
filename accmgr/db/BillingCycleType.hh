#ifndef __BILLINGCYCLETYPE__
#define __BILLINGCYCLETYPE__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class BillingCycleType:public SQLInterface
{
public:
    void insertData();
    void emptyData();
    vector<ST_BILLING_CYCLE_TYPE> loadAllData();
    virtual void prepareSQL();
    virtual void doParse();

public:
    ST_BILLING_CYCLE_TYPE billing_cycle_type;

private:
    int type;
    static string emptySQL;
    static string selectAllSQL;
    vector<ST_BILLING_CYCLE_TYPE> v_data;
    static string insSQL;
};
#endif
