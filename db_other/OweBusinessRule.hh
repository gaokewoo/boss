#ifndef __OWEBUSINESSRULE__
#define __OWEBUSINESSRULE__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class OweBusinessRule:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_OWE_BUSINESS_RULE owe_business_rule;

private:
    static string insSQL;
};
#endif
