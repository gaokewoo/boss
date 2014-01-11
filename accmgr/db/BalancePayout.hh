#ifndef __BALANCEPAYOUT__
#define __BALANCEPAYOUT__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class BalancePayout:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_BALANCE_PAYOUT balance_payout;

private:
    static string insSQL;
};
#endif
