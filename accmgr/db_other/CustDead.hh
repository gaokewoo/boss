#ifndef __CUSTDEAD__
#define __CUSTDEAD__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class CustDead:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_CUST_DEAD cust_dead;

private:
    static string insSQL;
};
#endif
