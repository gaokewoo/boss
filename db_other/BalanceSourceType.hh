#ifndef __BALANCESOURCETYPE__
#define __BALANCESOURCETYPE__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class BalanceSourceType:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_BALANCE_SOURCE_TYPE balance_source_type;

private:
    static string insSQL;
};
#endif
