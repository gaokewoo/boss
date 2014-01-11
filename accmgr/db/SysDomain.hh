#ifndef __SYSDOMAIN__
#define __SYSDOMAIN__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class SysDomain:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_SYS_DOMAIN sys_domain;

private:
    static string insSQL;
};
#endif
