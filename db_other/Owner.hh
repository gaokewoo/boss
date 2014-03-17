#ifndef __OWNER__
#define __OWNER__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class Owner:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_OWNER owner;

private:
    static string insSQL;
};
#endif
