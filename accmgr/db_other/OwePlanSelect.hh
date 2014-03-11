#ifndef __OWEPLANSELECT__
#define __OWEPLANSELECT__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class OwePlanSelect:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_OWE_PLAN_SELECT owe_plan_select;

private:
    static string insSQL;
};
#endif
