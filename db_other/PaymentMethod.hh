#ifndef __PAYMENTMETHOD__
#define __PAYMENTMETHOD__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class PaymentMethod:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_PAYMENT_METHOD payment_method;

private:
    static string insSQL;
};
#endif
