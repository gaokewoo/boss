#ifndef __ROUTECONTROLTABLE__
#define __ROUTECONTROLTABLE__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class RouteControlTable:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_ROUTE_CONTROL_TABLE route_control_table;

private:
    static string insSQL;
};
#endif
