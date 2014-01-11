#ifndef __REGION__
#define __REGION__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class Region:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_REGION region;

private:
    static string insSQL;
};
#endif
