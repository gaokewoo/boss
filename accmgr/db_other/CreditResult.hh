#ifndef __CREDITRESULT__
#define __CREDITRESULT__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class CreditResult:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_CREDIT_RESULT credit_result;

private:
    static string insSQL;
};
#endif
