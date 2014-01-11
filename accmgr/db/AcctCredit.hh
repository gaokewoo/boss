#ifndef __ACCTCREDIT__
#define __ACCTCREDIT__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class AcctCredit:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_ACCT_CREDIT acct_credit;

private:
    static string insSQL;
};
#endif
