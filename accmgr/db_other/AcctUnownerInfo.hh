#ifndef __ACCTUNOWNERINFO__
#define __ACCTUNOWNERINFO__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class AcctUnownerInfo:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_ACCT_UNOWNER_INFO acct_unowner_info;

private:
    static string insSQL;
};
#endif
