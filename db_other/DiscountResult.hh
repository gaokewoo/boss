#ifndef __DISCOUNTRESULT__
#define __DISCOUNTRESULT__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class DiscountResult:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_DISCOUNT_RESULT discount_result;

private:
    static string insSQL;
};
#endif
