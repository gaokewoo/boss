#ifndef __BALANCESHARERULEDEAD__
#define __BALANCESHARERULEDEAD__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class BalanceShareRuleDead:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_BALANCE_SHARE_RULE_DEAD balance_share_rule_dead;

private:
    static string insSQL;
};
#endif
