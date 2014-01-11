#ifndef __ZTSTAFFLOG__
#define __ZTSTAFFLOG__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class ZtStaffLog:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_ZT_STAFF_LOG zt_staff_log;

private:
    static string insSQL;
};
#endif
