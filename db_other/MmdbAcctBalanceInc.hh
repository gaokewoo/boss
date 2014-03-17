#ifndef __MMDBACCTBALANCEINC__
#define __MMDBACCTBALANCEINC__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class MmdbAcctBalanceInc:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_MMDB_ACCT_BALANCE_INC mmdb_acct_balance_inc;

private:
    static string insSQL;
};
#endif
