#ifndef __ACCTBALANCEDEAD__
#define __ACCTBALANCEDEAD__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class AcctBalanceDead:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_ACCT_BALANCE_DEAD acct_balance_dead;

private:
    static string insSQL;
};
#endif
