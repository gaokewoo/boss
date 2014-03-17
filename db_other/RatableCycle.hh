#ifndef __RATABLECYCLE__
#define __RATABLECYCLE__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class RatableCycle:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_RATABLE_CYCLE ratable_cycle;

private:
    static string insSQL;
};
#endif
