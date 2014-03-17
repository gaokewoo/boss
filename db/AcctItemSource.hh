#ifndef __ACCTITEMSOURCE__
#define __ACCTITEMSOURCE__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class AcctItemSource:public SQLInterface
{
public:
    void insertData();
    void emptyData();
    vector<ST_ACCT_ITEM_SOURCE> loadAllData();
    virtual void prepareSQL();
    virtual void doParse();

public:
    ST_ACCT_ITEM_SOURCE acct_item_source;

private:
    int type;
    static string emptySQL;
    static string selectAllSQL;
    vector<ST_ACCT_ITEM_SOURCE> v_data;
    static string insSQL;
};
#endif
