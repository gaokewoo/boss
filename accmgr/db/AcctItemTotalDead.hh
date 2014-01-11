#ifndef __ACCTITEMTOTALDEAD__
#define __ACCTITEMTOTALDEAD__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class AcctItemTotalDead:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_ACCT_ITEM_TOTAL_DEAD acct_item_total_dead;

private:
    static string insSQL;
};
#endif
