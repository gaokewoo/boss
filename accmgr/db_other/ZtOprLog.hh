#ifndef __ZTOPRLOG__
#define __ZTOPRLOG__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class ZtOprLog:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_ZT_OPR_LOG zt_opr_log;

private:
    static string insSQL;
};
#endif
