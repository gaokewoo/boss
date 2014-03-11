#ifndef __PRODUCTOFFEROBJECT__
#define __PRODUCTOFFEROBJECT__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class ProductOfferObject:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_PRODUCT_OFFER_OBJECT product_offer_object;

private:
    static string insSQL;
};
#endif
