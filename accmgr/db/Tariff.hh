#ifndef __TARIFF__
#define __TARIFF__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class Tariff:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_TARIFF tariff;

private:
    static string insSQL;
};
#endif
