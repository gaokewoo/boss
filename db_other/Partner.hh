#ifndef __PARTNER__
#define __PARTNER__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class Partner:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_PARTNER partner;

private:
    static string insSQL;
};
#endif
