#ifndef __BILLITEM__
#define __BILLITEM__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class BillItem:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_BILL_ITEM bill_item;

private:
    static string insSQL;
};
#endif
