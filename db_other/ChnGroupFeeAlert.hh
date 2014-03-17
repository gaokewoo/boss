#ifndef __CHNGROUPFEEALERT__
#define __CHNGROUPFEEALERT__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class ChnGroupFeeAlert:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_CHN_GROUP_FEE_ALERT chn_group_fee_alert;

private:
    static string insSQL;
};
#endif
