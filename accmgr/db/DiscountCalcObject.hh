#ifndef __DISCOUNTCALCOBJECT__
#define __DISCOUNTCALCOBJECT__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class DiscountCalcObject:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_DISCOUNT_CALC_OBJECT discount_calc_object;

private:
    static string insSQL;
};
#endif
