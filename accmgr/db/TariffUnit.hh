#ifndef __TARIFFUNIT__
#define __TARIFFUNIT__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class TariffUnit:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_TARIFF_UNIT tariff_unit;

private:
    static string insSQL;
};
#endif
