#ifndef __OWEBUSINESSINTERFACEHIS__
#define __OWEBUSINESSINTERFACEHIS__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class OweBusinessInterfaceHis:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_OWE_BUSINESS_INTERFACE_HIS owe_business_interface_his;

private:
    static string insSQL;
};
#endif
