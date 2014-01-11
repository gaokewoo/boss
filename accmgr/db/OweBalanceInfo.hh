#ifndef __OWEBALANCEINFO__
#define __OWEBALANCEINFO__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class OweBalanceInfo:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_OWE_BALANCE_INFO owe_balance_info;

private:
    static string insSQL;
};
#endif
