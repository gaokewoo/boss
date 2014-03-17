#ifndef __CUSTOWETOTAL__
#define __CUSTOWETOTAL__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class CustOweTotal:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_CUST_OWE_TOTAL cust_owe_total;

private:
    static string insSQL;
};
#endif
