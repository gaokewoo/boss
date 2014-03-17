#ifndef __SERVBILLINGMODE__
#define __SERVBILLINGMODE__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class ServBillingMode:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_SERV_BILLING_MODE serv_billing_mode;

private:
    static string insSQL;
};
#endif
