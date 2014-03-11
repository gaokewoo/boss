#ifndef __DISCOUNTTARGETOBJECT__
#define __DISCOUNTTARGETOBJECT__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class DiscountTargetObject:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_DISCOUNT_TARGET_OBJECT discount_target_object;

private:
    static string insSQL;
};
#endif
