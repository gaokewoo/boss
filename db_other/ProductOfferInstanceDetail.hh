#ifndef __PRODUCTOFFERINSTANCEDETAIL__
#define __PRODUCTOFFERINSTANCEDETAIL__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class ProductOfferInstanceDetail:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_PRODUCT_OFFER_INSTANCE_DETAIL product_offer_instance_detail;

private:
    static string insSQL;
};
#endif
