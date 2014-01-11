#ifndef __ACCTITEMOFF__
#define __ACCTITEMOFF__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class AcctItemOff:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_ACCT_ITEM_OFF acct_item_off;

private:
    static string insSQL;
};
#endif
