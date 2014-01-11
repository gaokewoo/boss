#ifndef __STOPSERVOWEBC__
#define __STOPSERVOWEBC__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class StopServOweBc:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_STOP_SERV_OWE_BC stop_serv_owe_bc;

private:
    static string insSQL;
};
#endif
