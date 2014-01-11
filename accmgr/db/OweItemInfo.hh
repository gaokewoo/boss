#ifndef __OWEITEMINFO__
#define __OWEITEMINFO__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class OweItemInfo:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_OWE_ITEM_INFO owe_item_info;

private:
    static string insSQL;
};
#endif
