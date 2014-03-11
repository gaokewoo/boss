#ifndef __SENDFEERULE__
#define __SENDFEERULE__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class SendFeeRule:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_SEND_FEE_RULE send_fee_rule;

private:
    static string insSQL;
};
#endif
