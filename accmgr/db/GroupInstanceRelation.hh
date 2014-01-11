#ifndef __GROUPINSTANCERELATION__
#define __GROUPINSTANCERELATION__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class GroupInstanceRelation:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_GROUP_INSTANCE_RELATION group_instance_relation;

private:
    static string insSQL;
};
#endif
