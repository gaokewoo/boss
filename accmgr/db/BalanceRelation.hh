#ifndef __BALANCERELATION__
#define __BALANCERELATION__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class BalanceRelation:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_BALANCE_RELATION balance_relation;

private:
    static string insSQL;
};
#endif
