#ifndef __ACCTITEMGROUP__
#define __ACCTITEMGROUP__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class AcctItemGroup:public SQLInterface
{
public:
    void insertData();
    void emptyData();
    vector<ST_ACCT_ITEM_GROUP> loadAllData();
    virtual void prepareSQL();
    virtual void doParse();

public:
    ST_ACCT_ITEM_GROUP acct_item_group;

private:
    int type;
    static string emptySQL;
    static string selectAllSQL;
    vector<ST_ACCT_ITEM_GROUP> v_data;
    static string insSQL;
};
#endif
