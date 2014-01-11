#ifndef __INTERESTRESPOND__
#define __INTERESTRESPOND__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class InterestRespond:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_INTEREST_RESPOND interest_respond;

private:
    static string insSQL;
};
#endif
