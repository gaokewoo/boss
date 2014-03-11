#ifndef __BATCHLOGDET__
#define __BATCHLOGDET__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class BatchLogDet:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_BATCH_LOG_DET batch_log_det;

private:
    static string insSQL;
};
#endif
