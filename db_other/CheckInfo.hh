#ifndef __CHECKINFO__
#define __CHECKINFO__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class CheckInfo:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_CHECK_INFO check_info;

private:
    static string insSQL;
};
#endif
