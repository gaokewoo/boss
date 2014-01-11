#ifndef __BAND__
#define __BAND__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class Band:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_BAND band;

private:
    static string insSQL;
};
#endif
