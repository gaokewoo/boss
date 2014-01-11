#ifndef __PAYMENTPLANDEAD__
#define __PAYMENTPLANDEAD__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class PaymentPlanDead:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_PAYMENT_PLAN_DEAD payment_plan_dead;

private:
    static string insSQL;
};
#endif
