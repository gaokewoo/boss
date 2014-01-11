#ifndef __ZTOWETOTAL__
#define __ZTOWETOTAL__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class ZtOweTotal:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_ZT_OWE_TOTAL zt_owe_total;

private:
    static string insSQL;
};
#endif
