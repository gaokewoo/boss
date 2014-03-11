#ifndef __ACCTITEMDEAD__
#define __ACCTITEMDEAD__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class AcctItemDead:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_ACCT_ITEM_DEAD acct_item_dead;

private:
    static string insSQL;
};
#endif
