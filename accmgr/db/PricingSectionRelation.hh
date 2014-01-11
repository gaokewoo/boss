#ifndef __PRICINGSECTIONRELATION__
#define __PRICINGSECTIONRELATION__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class PricingSectionRelation:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_PRICING_SECTION_RELATION pricing_section_relation;

private:
    static string insSQL;
};
#endif
