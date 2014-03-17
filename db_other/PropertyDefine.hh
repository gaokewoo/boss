#ifndef __PROPERTYDEFINE__
#define __PROPERTYDEFINE__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class PropertyDefine:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_PROPERTY_DEFINE property_define;

private:
    static string insSQL;
};
#endif
