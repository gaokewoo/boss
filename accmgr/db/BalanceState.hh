#ifndef __BALANCESTATE__
#define __BALANCESTATE__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class BalanceState:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_BALANCE_STATE balance_state;

private:
    static string insSQL;
};
#endif
