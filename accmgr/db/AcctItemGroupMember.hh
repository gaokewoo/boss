#ifndef __ACCTITEMGROUPMEMBER__
#define __ACCTITEMGROUPMEMBER__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class AcctItemGroupMember:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_ACCT_ITEM_GROUP_MEMBER acct_item_group_member;

private:
    static string insSQL;
};
#endif
