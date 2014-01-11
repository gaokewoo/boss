#ifndef __EVALPLAN__
#define __EVALPLAN__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class EvalPlan:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_EVAL_PLAN eval_plan;

private:
    static string insSQL;
};
#endif
