#ifndef __GROUPMEMBERTYPE__
#define __GROUPMEMBERTYPE__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class GroupMemberType:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_GROUP_MEMBER_TYPE group_member_type;

private:
    static string insSQL;
};
#endif
