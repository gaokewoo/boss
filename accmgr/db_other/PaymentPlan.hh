#ifndef __PAYMENTPLAN__
#define __PAYMENTPLAN__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class PaymentPlan:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_PAYMENT_PLAN payment_plan;

private:
    static string insSQL;
};
#endif
