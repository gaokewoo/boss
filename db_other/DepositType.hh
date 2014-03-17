#ifndef __DEPOSITTYPE__
#define __DEPOSITTYPE__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class DepositType:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_DEPOSIT_TYPE deposit_type;

private:
    static string insSQL;
};
#endif
