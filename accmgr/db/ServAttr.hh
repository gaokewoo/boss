#ifndef __SERVATTR__
#define __SERVATTR__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class ServAttr:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_SERV_ATTR serv_attr;

private:
    static string insSQL;
};
#endif
