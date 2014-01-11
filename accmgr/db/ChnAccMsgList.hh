#ifndef __CHNACCMSGLIST__
#define __CHNACCMSGLIST__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class ChnAccMsgList:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_CHN_ACC_MSG_LIST chn_acc_msg_list;

private:
    static string insSQL;
};
#endif
