#ifndef __BILLACCTITEM__
#define __BILLACCTITEM__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class BillAcctItem:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_BILL_ACCT_ITEM bill_acct_item;

private:
    static string insSQL;
};
#endif
