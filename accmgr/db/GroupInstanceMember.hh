#ifndef __GROUPINSTANCEMEMBER__
#define __GROUPINSTANCEMEMBER__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class GroupInstanceMember:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_GROUP_INSTANCE_MEMBER group_instance_member;

private:
    static string insSQL;
};
#endif
