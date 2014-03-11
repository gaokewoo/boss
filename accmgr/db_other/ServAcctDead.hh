#ifndef __SERVACCTDEAD__
#define __SERVACCTDEAD__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class ServAcctDead:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_SERV_ACCT_DEAD serv_acct_dead;

private:
    static string insSQL;
};
#endif
