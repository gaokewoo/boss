#ifndef __ZONE__
#define __ZONE__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class Zone:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_ZONE zone;

private:
    static string insSQL;
};
#endif
