#ifndef __CHARGEADJUSTLOG__
#define __CHARGEADJUSTLOG__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class ChargeAdjustLog:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_CHARGE_ADJUST_LOG charge_adjust_log;

private:
    static string insSQL;
};
#endif
