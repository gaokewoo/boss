#ifndef __OWEBUSINESSRELA__
#define __OWEBUSINESSRELA__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class OweBusinessRela:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_OWE_BUSINESS_RELA owe_business_rela;

private:
    static string insSQL;
};
#endif
