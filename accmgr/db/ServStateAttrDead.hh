#ifndef __SERVSTATEATTRDEAD__
#define __SERVSTATEATTRDEAD__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class ServStateAttrDead:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_SERV_STATE_ATTR_DEAD serv_state_attr_dead;

private:
    static string insSQL;
};
#endif
