#ifndef __STOPSERVOWECJ__
#define __STOPSERVOWECJ__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class StopServOweCj:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_STOP_SERV_OWE_CJ stop_serv_owe_cj;

private:
    static string insSQL;
};
#endif
