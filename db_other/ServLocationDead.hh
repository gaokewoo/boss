#ifndef __SERVLOCATIONDEAD__
#define __SERVLOCATIONDEAD__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class ServLocationDead:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_SERV_LOCATION_DEAD serv_location_dead;

private:
    static string insSQL;
};
#endif
