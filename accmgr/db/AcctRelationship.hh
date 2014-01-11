#ifndef __ACCTRELATIONSHIP__
#define __ACCTRELATIONSHIP__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class AcctRelationship:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_ACCT_RELATIONSHIP acct_relationship;

private:
    static string insSQL;
};
#endif
