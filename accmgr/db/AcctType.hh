#ifndef __ACCTTYPE__
#define __ACCTTYPE__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class AcctType:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_ACCT_TYPE acct_type;

private:
    static string insSQL;
};
#endif
