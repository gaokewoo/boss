#ifndef __ACCTITEMGROUP__
#define __ACCTITEMGROUP__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class AcctItemGroup:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_ACCT_ITEM_GROUP acct_item_group;

private:
    static string insSQL;
};
#endif
