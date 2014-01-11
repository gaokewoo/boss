#ifndef __GROUPINSTANCE__
#define __GROUPINSTANCE__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class GroupInstance:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_GROUP_INSTANCE group_instance;

private:
    static string insSQL;
};
#endif
