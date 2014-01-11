#ifndef __OWEBALANCETMP__
#define __OWEBALANCETMP__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class OweBalanceTmp:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_OWE_BALANCE_TMP owe_balance_tmp;

private:
    static string insSQL;
};
#endif
