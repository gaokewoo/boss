#ifndef __STAFFPRIVILEGE__
#define __STAFFPRIVILEGE__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class StaffPrivilege:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_STAFF_PRIVILEGE staff_privilege;

private:
    static string insSQL;
};
#endif
