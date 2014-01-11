#ifndef __PAYMENTRULE__
#define __PAYMENTRULE__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class PaymentRule:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_PAYMENT_RULE payment_rule;

private:
    static string insSQL;
};
#endif
