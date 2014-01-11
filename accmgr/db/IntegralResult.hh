#ifndef __INTEGRALRESULT__
#define __INTEGRALRESULT__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class IntegralResult:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_INTEGRAL_RESULT integral_result;

private:
    static string insSQL;
};
#endif
