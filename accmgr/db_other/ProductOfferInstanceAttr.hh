#ifndef __PRODUCTOFFERINSTANCEATTR__
#define __PRODUCTOFFERINSTANCEATTR__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class ProductOfferInstanceAttr:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_PRODUCT_OFFER_INSTANCE_ATTR product_offer_instance_attr;

private:
    static string insSQL;
};
#endif
