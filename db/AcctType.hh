#ifndef __ACCTTYPE__
#define __ACCTTYPE__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class AcctType:public SQLInterface
{
public:
    void insertData();
    void emptyData();
    vector<ST_ACCT_TYPE> loadAllData();
    virtual void prepareSQL();
    virtual void doParse();

public:
    ST_ACCT_TYPE acct_type;

private:
    int type;
    static string emptySQL;
    static string selectAllSQL;
    vector<ST_ACCT_TYPE> v_data;
    static string insSQL;
};
#endif
