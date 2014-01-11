#ifndef __DISCOUNTEXPRESS__
#define __DISCOUNTEXPRESS__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class DiscountExpress:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_DISCOUNT_EXPRESS discount_express;

private:
    static string insSQL;
};
#endif
