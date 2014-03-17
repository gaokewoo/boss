#ifndef __SERVDEAD__
#define __SERVDEAD__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class ServDead:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_SERV_DEAD serv_dead;

private:
    static string insSQL;
};
#endif
