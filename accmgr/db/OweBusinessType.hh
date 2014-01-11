#ifndef __OWEBUSINESSTYPE__
#define __OWEBUSINESSTYPE__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class OweBusinessType:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_OWE_BUSINESS_TYPE owe_business_type;

private:
    static string insSQL;
};
#endif
