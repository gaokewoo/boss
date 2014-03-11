#ifndef __MONTHPAYSHORTMSG__
#define __MONTHPAYSHORTMSG__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class MonthPayShortMsg:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_MONTH_PAY_SHORT_MSG month_pay_short_msg;

private:
    static string insSQL;
};
#endif
