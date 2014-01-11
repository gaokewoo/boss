#ifndef __ACCTGROUP__
#define __ACCTGROUP__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class AcctGroup:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_ACCT_GROUP acct_group;

private:
    static string insSQL;
};
#endif
