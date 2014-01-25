#ifndef __BILLINGREGION__
#define __BILLINGREGION__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class BillingRegion:public SQLInterface
{
public:
    void insertData();
    void emptyData();
    vector<ST_BILLING_REGION> loadAllData();
    virtual void prepareSQL();
    virtual void doParse();

public:
    ST_BILLING_REGION billing_region;

private:
    int type;
    static string emptySQL;
    static string selectAllSQL;
    vector<ST_BILLING_REGION> v_data;
    static string insSQL;
};
#endif
