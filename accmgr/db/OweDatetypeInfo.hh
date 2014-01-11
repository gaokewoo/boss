#ifndef __OWEDATETYPEINFO__
#define __OWEDATETYPEINFO__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class OweDatetypeInfo:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_OWE_DATETYPE_INFO owe_datetype_info;

private:
    static string insSQL;
};
#endif
