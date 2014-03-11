#ifndef __SPECIALPAYMENTDESC__
#define __SPECIALPAYMENTDESC__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class SpecialPaymentDesc:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_SPECIAL_PAYMENT_DESC special_payment_desc;

private:
    static string insSQL;
};
#endif
