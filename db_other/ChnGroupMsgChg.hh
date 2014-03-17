#ifndef __CHNGROUPMSGCHG__
#define __CHNGROUPMSGCHG__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class ChnGroupMsgChg:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_CHN_GROUP_MSG_CHG chn_group_msg_chg;

private:
    static string insSQL;
};
#endif
