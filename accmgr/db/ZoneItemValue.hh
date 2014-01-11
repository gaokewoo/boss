#ifndef __ZONEITEMVALUE__
#define __ZONEITEMVALUE__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class ZoneItemValue:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_ZONE_ITEM_VALUE zone_item_value;

private:
    static string insSQL;
};
#endif
