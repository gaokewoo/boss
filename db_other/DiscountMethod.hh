#ifndef __DISCOUNTMETHOD__
#define __DISCOUNTMETHOD__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class DiscountMethod:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_DISCOUNT_METHOD discount_method;

private:
    static string insSQL;
};
#endif
