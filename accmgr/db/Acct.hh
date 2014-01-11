#ifndef __ACCT__
#define __ACCT__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class Acct:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_ACCT acct;

private:
    static string insSQL;
};
#endif
