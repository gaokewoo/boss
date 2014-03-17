#ifndef __BALANCEPRESENTINFO__
#define __BALANCEPRESENTINFO__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class BalancePresentInfo:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_BALANCE_PRESENT_INFO balance_present_info;

private:
    static string insSQL;
};
#endif
