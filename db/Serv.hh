#ifndef __SERV__
#define __SERV__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class Serv:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_SERV serv;

private:
    static string insSQL;
};
#endif
