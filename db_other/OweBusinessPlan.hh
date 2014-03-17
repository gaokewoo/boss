#ifndef __OWEBUSINESSPLAN__
#define __OWEBUSINESSPLAN__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class OweBusinessPlan:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_OWE_BUSINESS_PLAN owe_business_plan;

private:
    static string insSQL;
};
#endif
