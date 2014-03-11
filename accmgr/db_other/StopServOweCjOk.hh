#ifndef __STOPSERVOWECJOK__
#define __STOPSERVOWECJOK__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class StopServOweCjOk:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_STOP_SERV_OWE_CJ_OK stop_serv_owe_cj_ok;

private:
    static string insSQL;
};
#endif
