#ifndef __PRICINGSECTIONTYPE__
#define __PRICINGSECTIONTYPE__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class PricingSectionType:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_PRICING_SECTION_TYPE pricing_section_type;

private:
    static string insSQL;
};
#endif
