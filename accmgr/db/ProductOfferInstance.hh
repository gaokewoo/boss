#ifndef __PRODUCTOFFERINSTANCE__
#define __PRODUCTOFFERINSTANCE__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class ProductOfferInstance:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_PRODUCT_OFFER_INSTANCE product_offer_instance;

private:
    static string insSQL;
};
#endif
