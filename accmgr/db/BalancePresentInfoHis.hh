#ifndef __BALANCEPRESENTINFOHIS__
#define __BALANCEPRESENTINFOHIS__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class BalancePresentInfoHis:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_BALANCE_PRESENT_INFO_HIS balance_present_info_his;

private:
    static string insSQL;
};
#endif
