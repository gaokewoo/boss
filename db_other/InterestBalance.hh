#ifndef __INTERESTBALANCE__
#define __INTERESTBALANCE__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class InterestBalance:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_INTEREST_BALANCE interest_balance;

private:
    static string insSQL;
};
#endif
