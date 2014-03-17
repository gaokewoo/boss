#ifndef __BALANCESOURCETYPE__
#define __BALANCESOURCETYPE__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class BalanceSourceType:public SQLInterface
{
public:
    void insertData();
    void emptyData();
    vector<ST_BALANCE_SOURCE_TYPE> loadAllData();
    virtual void prepareSQL();
    virtual void doParse();

public:
    ST_BALANCE_SOURCE_TYPE balance_source_type;

private:
    int type;
    static string emptySQL;
    static string selectAllSQL;
    vector<ST_BALANCE_SOURCE_TYPE> v_data;
    static string insSQL;
};
#endif
