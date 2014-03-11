#ifndef __PROPERTYREF__
#define __PROPERTYREF__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class PropertyRef:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_PROPERTY_REF property_ref;

private:
    static string insSQL;
};
#endif
