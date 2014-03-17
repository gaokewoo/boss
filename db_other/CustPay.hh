#ifndef __CUSTPAY__
#define __CUSTPAY__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class CustPay:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_CUST_PAY cust_pay;

private:
    static string insSQL;
};
#endif
