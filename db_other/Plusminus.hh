#ifndef __PLUSMINUS__
#define __PLUSMINUS__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class Plusminus:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_PLUSMINUS plusminus;

private:
    static string insSQL;
};
#endif
