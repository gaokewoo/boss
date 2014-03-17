#ifndef __OWEOBJECT__
#define __OWEOBJECT__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class OweObject:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_OWE_OBJECT owe_object;

private:
    static string insSQL;
};
#endif
