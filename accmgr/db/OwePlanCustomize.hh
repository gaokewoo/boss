#ifndef __OWEPLANCUSTOMIZE__
#define __OWEPLANCUSTOMIZE__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class OwePlanCustomize:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_OWE_PLAN_CUSTOMIZE owe_plan_customize;

private:
    static string insSQL;
};
#endif
