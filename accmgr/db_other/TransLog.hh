#ifndef __TRANSLOG__
#define __TRANSLOG__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class TransLog:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_TRANS_LOG trans_log;

private:
    static string insSQL;
};
#endif
