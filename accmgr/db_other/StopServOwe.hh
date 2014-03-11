#ifndef __STOPSERVOWE__
#define __STOPSERVOWE__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class StopServOwe:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_STOP_SERV_OWE stop_serv_owe;

private:
    static string insSQL;
};
#endif
