#ifndef __CREDITGRADERULE__
#define __CREDITGRADERULE__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class CreditGradeRule:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_CREDIT_GRADE_RULE credit_grade_rule;

private:
    static string insSQL;
};
#endif
