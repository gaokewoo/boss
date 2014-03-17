#ifndef __STOPSERVSTATE__
#define __STOPSERVSTATE__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class StopServState:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_STOP_SERV_STATE stop_serv_state;

private:
    static string insSQL;
};
#endif
