#ifndef __BILLVARIABLE__
#define __BILLVARIABLE__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class BillVariable:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_BILL_VARIABLE bill_variable;

private:
    static string insSQL;
};
#endif
