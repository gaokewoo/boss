#ifndef __RATABLECYCLETYPE__
#define __RATABLECYCLETYPE__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class RatableCycleType:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_RATABLE_CYCLE_TYPE ratable_cycle_type;

private:
    static string insSQL;
};
#endif
