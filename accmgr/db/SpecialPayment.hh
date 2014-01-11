#ifndef __SPECIALPAYMENT__
#define __SPECIALPAYMENT__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class SpecialPayment:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_SPECIAL_PAYMENT special_payment;

private:
    static string insSQL;
};
#endif
