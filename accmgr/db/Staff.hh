#ifndef __STAFF__
#define __STAFF__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class Staff:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_STAFF staff;

private:
    static string insSQL;
};
#endif
