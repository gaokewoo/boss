#ifndef __PRODUCTOFFERDETAIL__
#define __PRODUCTOFFERDETAIL__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class ProductOfferDetail:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_PRODUCT_OFFER_DETAIL product_offer_detail;

private:
    static string insSQL;
};
#endif
