#ifndef __ACCTBALANCELOG__
#define __ACCTBALANCELOG__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class AcctBalanceLog:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_ACCT_BALANCE_LOG acct_balance_log;

private:
    static string insSQL;
};
#endif
