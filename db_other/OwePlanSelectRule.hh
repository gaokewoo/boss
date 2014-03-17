#ifndef __OWEPLANSELECTRULE__
#define __OWEPLANSELECTRULE__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class OwePlanSelectRule:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_OWE_PLAN_SELECT_RULE owe_plan_select_rule;

private:
    static string insSQL;
};
#endif
