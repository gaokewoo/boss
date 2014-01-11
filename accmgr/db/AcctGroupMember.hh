#ifndef __ACCTGROUPMEMBER__
#define __ACCTGROUPMEMBER__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class AcctGroupMember:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_ACCT_GROUP_MEMBER acct_group_member;

private:
    static string insSQL;
};
#endif
