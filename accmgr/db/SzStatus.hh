#ifndef __SZSTATUS__
#define __SZSTATUS__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class SzStatus:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_SZ_STATUS sz_status;

private:
    static string insSQL;
};
#endif
