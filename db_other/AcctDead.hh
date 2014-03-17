#ifndef __ACCTDEAD__
#define __ACCTDEAD__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class AcctDead:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_ACCT_DEAD acct_dead;

private:
    static string insSQL;
};
#endif
