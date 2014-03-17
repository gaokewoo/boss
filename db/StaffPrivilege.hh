#ifndef __STAFFPRIVILEGE__
#define __STAFFPRIVILEGE__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class StaffPrivilege:public SQLInterface
{
public:
    void insertData();
    void emptyData();
    vector<ST_STAFF_PRIVILEGE> loadAllData();
    virtual void prepareSQL();
    virtual void doParse();

public:
    ST_STAFF_PRIVILEGE staff_privilege;

private:
    int type;
    static string emptySQL;
    static string selectAllSQL;
    vector<ST_STAFF_PRIVILEGE> v_data;
    static string insSQL;
};
#endif
