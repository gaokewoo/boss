#ifndef __ACCTITEMTOTAL__
#define __ACCTITEMTOTAL__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class AcctItemTotal:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_ACCT_ITEM_TOTAL acct_item_total;

private:
    static string insSQL;
};
#endif
