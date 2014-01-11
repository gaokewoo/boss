#ifndef __COLLECTTOTAL__
#define __COLLECTTOTAL__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class CollectTotal:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_COLLECT_TOTAL collect_total;

private:
    static string insSQL;
};
#endif
