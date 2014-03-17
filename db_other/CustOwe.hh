#ifndef __CUSTOWE__
#define __CUSTOWE__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class CustOwe:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_CUST_OWE cust_owe;

private:
    static string insSQL;
};
#endif
