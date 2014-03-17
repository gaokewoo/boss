#ifndef __CUST__
#define __CUST__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class Cust:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_CUST cust;

private:
    static string insSQL;
};
#endif
