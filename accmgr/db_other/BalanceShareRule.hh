#ifndef __BALANCESHARERULE__
#define __BALANCESHARERULE__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class BalanceShareRule:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_BALANCE_SHARE_RULE balance_share_rule;

private:
    static string insSQL;
};
#endif
