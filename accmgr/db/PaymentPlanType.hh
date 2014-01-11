#ifndef __PAYMENTPLANTYPE__
#define __PAYMENTPLANTYPE__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class PaymentPlanType:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_PAYMENT_PLAN_TYPE payment_plan_type;

private:
    static string insSQL;
};
#endif
