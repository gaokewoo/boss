#ifndef __DISCOUNTTIMELIMIT__
#define __DISCOUNTTIMELIMIT__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class DiscountTimeLimit:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_DISCOUNT_TIME_LIMIT discount_time_limit;

private:
    static string insSQL;
};
#endif
