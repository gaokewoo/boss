#ifndef __TARIFFREFTYPE__
#define __TARIFFREFTYPE__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class TariffRefType:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_TARIFF_REF_TYPE tariff_ref_type;

private:
    static string insSQL;
};
#endif
