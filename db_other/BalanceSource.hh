#ifndef __BALANCESOURCE__
#define __BALANCESOURCE__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class BalanceSource:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_BALANCE_SOURCE balance_source;

private:
    static string insSQL;
};
#endif
