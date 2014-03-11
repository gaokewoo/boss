#ifndef __GROUPTYPE__
#define __GROUPTYPE__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class GroupType:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_GROUP_TYPE group_type;

private:
    static string insSQL;
};
#endif
