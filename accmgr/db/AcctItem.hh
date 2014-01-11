#ifndef __ACCTITEM__
#define __ACCTITEM__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class AcctItem:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_ACCT_ITEM acct_item;

private:
    static string insSQL;
};
#endif
