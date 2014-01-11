#ifndef __SERVACCT__
#define __SERVACCT__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class ServAcct:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_SERV_ACCT serv_acct;

private:
    static string insSQL;
};
#endif
