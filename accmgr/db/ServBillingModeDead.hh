#ifndef __SERVBILLINGMODEDEAD__
#define __SERVBILLINGMODEDEAD__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class ServBillingModeDead:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_SERV_BILLING_MODE_DEAD serv_billing_mode_dead;

private:
    static string insSQL;
};
#endif
