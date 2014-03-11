#ifndef __ACCTITEMTYPE__
#define __ACCTITEMTYPE__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class AcctItemType:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_ACCT_ITEM_TYPE acct_item_type;

private:
    static string insSQL;
};
#endif
