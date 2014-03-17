#ifndef __OWEBUSINESSATTR__
#define __OWEBUSINESSATTR__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class OweBusinessAttr:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_OWE_BUSINESS_ATTR owe_business_attr;

private:
    static string insSQL;
};
#endif
