#ifndef __RATABLERESOURCEACCUMULATOR__
#define __RATABLERESOURCEACCUMULATOR__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class RatableResourceAccumulator:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_RATABLE_RESOURCE_ACCUMULATOR ratable_resource_accumulator;

private:
    static string insSQL;
};
#endif
