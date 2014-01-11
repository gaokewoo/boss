#ifndef __ACCTLOGOUT__
#define __ACCTLOGOUT__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class AcctLogout:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_ACCT_LOGOUT acct_logout;

private:
    static string insSQL;
};
#endif
