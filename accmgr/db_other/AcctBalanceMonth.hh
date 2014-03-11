#ifndef __ACCTBALANCEMONTH__
#define __ACCTBALANCEMONTH__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class AcctBalanceMonth:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_ACCT_BALANCE_MONTH acct_balance_month;

private:
    static string insSQL;
};
#endif
