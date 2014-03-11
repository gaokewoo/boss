#ifndef __ZONEITEM__
#define __ZONEITEM__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class ZoneItem:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_ZONE_ITEM zone_item;

private:
    static string insSQL;
};
#endif
