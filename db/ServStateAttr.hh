#ifndef __SERVSTATEATTR__
#define __SERVSTATEATTR__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class ServStateAttr:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_SERV_STATE_ATTR serv_state_attr;

private:
    static string insSQL;
};
#endif
