#ifndef __DISCOUNTREPATITIONTYPE__
#define __DISCOUNTREPATITIONTYPE__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class DiscountRepatitionType:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_DISCOUNT_REPATITION_TYPE discount_repatition_type;

private:
    static string insSQL;
};
#endif
