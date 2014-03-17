#ifndef __PAYMENTMETHOD__
#define __PAYMENTMETHOD__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class PaymentMethod:public SQLInterface
{
public:
    void insertData();
    void emptyData();
    vector<ST_PAYMENT_METHOD> loadAllData();
    virtual void prepareSQL();
    virtual void doParse();

public:
    ST_PAYMENT_METHOD payment_method;

private:
    int type;
    static string emptySQL;
    static string selectAllSQL;
    vector<ST_PAYMENT_METHOD> v_data;
    static string insSQL;
};
#endif
