#ifndef __GROUPINSTANCEROLE__
#define __GROUPINSTANCEROLE__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class GroupInstanceRole:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_GROUP_INSTANCE_ROLE group_instance_role;

private:
    static string insSQL;
};
#endif
