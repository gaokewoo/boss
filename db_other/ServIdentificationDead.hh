#ifndef __SERVIDENTIFICATIONDEAD__
#define __SERVIDENTIFICATIONDEAD__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class ServIdentificationDead:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_SERV_IDENTIFICATION_DEAD serv_identification_dead;

private:
    static string insSQL;
};
#endif
