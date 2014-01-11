#ifndef __SERVSTATEDESC__
#define __SERVSTATEDESC__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class ServStateDesc:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_SERV_STATE_DESC serv_state_desc;

private:
    static string insSQL;
};
#endif
