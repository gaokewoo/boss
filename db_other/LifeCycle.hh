#ifndef __LIFECYCLE__
#define __LIFECYCLE__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class LifeCycle:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_LIFE_CYCLE life_cycle;

private:
    static string insSQL;
};
#endif
