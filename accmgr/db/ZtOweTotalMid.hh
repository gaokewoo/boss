#ifndef __ZTOWETOTALMID__
#define __ZTOWETOTALMID__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class ZtOweTotalMid:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_ZT_OWE_TOTAL_MID zt_owe_total_mid;

private:
    static string insSQL;
};
#endif
