#ifndef __INTERESTRATE__
#define __INTERESTRATE__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class InterestRate:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_INTEREST_RATE interest_rate;

private:
    static string insSQL;
};
#endif
