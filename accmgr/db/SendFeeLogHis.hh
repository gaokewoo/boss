#ifndef __SENDFEELOGHIS__
#define __SENDFEELOGHIS__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class SendFeeLogHis:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_SEND_FEE_LOG_HIS send_fee_log_his;

private:
    static string insSQL;
};
#endif
