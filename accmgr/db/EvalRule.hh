#ifndef __EVALRULE__
#define __EVALRULE__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class EvalRule:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_EVAL_RULE eval_rule;

private:
    static string insSQL;
};
#endif
