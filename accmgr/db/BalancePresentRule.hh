#ifndef __BALANCEPRESENTRULE__
#define __BALANCEPRESENTRULE__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class BalancePresentRule:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_BALANCE_PRESENT_RULE balance_present_rule;

private:
    static string insSQL;
};
#endif
