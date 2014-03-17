#ifndef __PRODUCTOFFERPARAMINSTANCE__
#define __PRODUCTOFFERPARAMINSTANCE__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class ProductOfferParamInstance:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_PRODUCT_OFFER_PARAM_INSTANCE product_offer_param_instance;

private:
    static string insSQL;
};
#endif
