#ifndef __ACCTBALANCE__
#define __ACCTBALANCE__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class AcctBalance:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_ACCT_BALANCE acct_balance;

private:
    static string insSQL;
};
#endif
