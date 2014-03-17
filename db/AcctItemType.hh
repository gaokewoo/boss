#ifndef __ACCTITEMTYPE__
#define __ACCTITEMTYPE__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class AcctItemType:public SQLInterface
{
public:
    void insertData();
    void emptyData();
    vector<ST_ACCT_ITEM_TYPE> loadAllData();
    virtual void prepareSQL();
    virtual void doParse();

public:
    ST_ACCT_ITEM_TYPE acct_item_type;

private:
    int type;
    static string emptySQL;
    static string selectAllSQL;
    vector<ST_ACCT_ITEM_TYPE> v_data;
    static string insSQL;
};
#endif
