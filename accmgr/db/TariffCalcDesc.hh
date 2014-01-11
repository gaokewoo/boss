#ifndef __TARIFFCALCDESC__
#define __TARIFFCALCDESC__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class TariffCalcDesc:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_TARIFF_CALC_DESC tariff_calc_desc;

private:
    static string insSQL;
};
#endif
