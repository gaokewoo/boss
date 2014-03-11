#ifndef __SERVATTRDEAD__
#define __SERVATTRDEAD__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class ServAttrDead:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_SERV_ATTR_DEAD serv_attr_dead;

private:
    static string insSQL;
};
#endif
