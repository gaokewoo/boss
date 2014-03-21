#ifndef __ACCTITEMADJUSTED__
#define __ACCTITEMADJUSTED__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class AcctItemAdjusted:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_ACCT_ITEM_ADJUSTED acct_item_adjusted;

private:
    static string insSQL;
};
#endif
