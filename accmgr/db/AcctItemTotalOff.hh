#ifndef __ACCTITEMTOTALOFF__
#define __ACCTITEMTOTALOFF__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class AcctItemTotalOff:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_ACCT_ITEM_TOTAL_OFF acct_item_total_off;

private:
    static string insSQL;
};
#endif
