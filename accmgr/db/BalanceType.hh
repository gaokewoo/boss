#ifndef __BALANCETYPE__
#define __BALANCETYPE__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class BalanceType:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_BALANCE_TYPE balance_type;

private:
    static string insSQL;
};
#endif
