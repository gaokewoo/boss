#ifndef __PRODUCTOFFER__
#define __PRODUCTOFFER__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class ProductOffer:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_PRODUCT_OFFER product_offer;

private:
    static string insSQL;
};
#endif
