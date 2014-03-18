#ifndef __ACCTITEMGROUPMEMBER__
#define __ACCTITEMGROUPMEMBER__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class AcctItemGroupMember:public SQLInterface
{
public:
    void insertData();
    void emptyData();
    vector<ST_ACCT_ITEM_GROUP_MEMBER> loadAllData();
    virtual void prepareSQL();
    virtual void doParse();

public:
    ST_ACCT_ITEM_GROUP_MEMBER acct_item_group_member;

private:
    int type;
    static string emptySQL;
    static string selectAllSQL;
    vector<ST_ACCT_ITEM_GROUP_MEMBER> v_data;
    static string insSQL;
};
#endif
