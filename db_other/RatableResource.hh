#ifndef __RATABLERESOURCE__
#define __RATABLERESOURCE__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class RatableResource:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_RATABLE_RESOURCE ratable_resource;

private:
    static string insSQL;
};
#endif
