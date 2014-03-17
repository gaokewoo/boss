#ifndef __PRODUCTOFFERPARAM__
#define __PRODUCTOFFERPARAM__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class ProductOfferParam:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_PRODUCT_OFFER_PARAM product_offer_param;

private:
    static string insSQL;
};
#endif
