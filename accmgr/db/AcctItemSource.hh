#ifndef __ACCTITEMSOURCE__
#define __ACCTITEMSOURCE__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class AcctItemSource:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_ACCT_ITEM_SOURCE acct_item_source;

private:
    static string insSQL;
};
#endif
