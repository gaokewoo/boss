#ifndef __OWEBUSINESSINTERFACE__
#define __OWEBUSINESSINTERFACE__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class OweBusinessInterface:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_OWE_BUSINESS_INTERFACE owe_business_interface;

private:
    static string insSQL;
};
#endif
