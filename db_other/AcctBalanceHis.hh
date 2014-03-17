#ifndef __ACCTBALANCEHIS__
#define __ACCTBALANCEHIS__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class AcctBalanceHis:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_ACCT_BALANCE_HIS acct_balance_his;

private:
    static string insSQL;
};
#endif
