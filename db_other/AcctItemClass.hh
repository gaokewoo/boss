#ifndef __ACCTITEMCLASS__
#define __ACCTITEMCLASS__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class AcctItemClass:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_ACCT_ITEM_CLASS acct_item_class;

private:
    static string insSQL;
};
#endif
