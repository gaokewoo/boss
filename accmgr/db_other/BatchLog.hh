#ifndef __BATCHLOG__
#define __BATCHLOG__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class BatchLog:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_BATCH_LOG batch_log;

private:
    static string insSQL;
};
#endif
