#ifndef __BALANCEACCTITEMPAYED__
#define __BALANCEACCTITEMPAYED__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class BalanceAcctItemPayed:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_BALANCE_ACCT_ITEM_PAYED balance_acct_item_payed;

private:
    static string insSQL;
};
#endif
