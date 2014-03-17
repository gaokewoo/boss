#ifndef __BILLINTERFACE__
#define __BILLINTERFACE__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class BillInterface:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_BILL_INTERFACE bill_interface;

private:
    static string insSQL;
};
#endif
