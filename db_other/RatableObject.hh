#ifndef __RATABLEOBJECT__
#define __RATABLEOBJECT__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class RatableObject:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_RATABLE_OBJECT ratable_object;

private:
    static string insSQL;
};
#endif
