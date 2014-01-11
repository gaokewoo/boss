#ifndef __PAYINFOHIS__
#define __PAYINFOHIS__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class PayInfoHis:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_PAY_INFO_HIS pay_info_his;

private:
    static string insSQL;
};
#endif
