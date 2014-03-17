#ifndef __PRODUCTOFFERATTR__
#define __PRODUCTOFFERATTR__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class ProductOfferAttr:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_PRODUCT_OFFER_ATTR product_offer_attr;

private:
    static string insSQL;
};
#endif
