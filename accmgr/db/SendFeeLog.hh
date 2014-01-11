#ifndef __SENDFEELOG__
#define __SENDFEELOG__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class SendFeeLog:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_SEND_FEE_LOG send_fee_log;

private:
    static string insSQL;
};
#endif
