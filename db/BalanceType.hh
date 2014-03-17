#ifndef __BALANCETYPE__
#define __BALANCETYPE__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class BalanceType:public SQLInterface
{
public:
    void insertData();
    void emptyData();
    vector<ST_BALANCE_TYPE> loadAllData();
    virtual void prepareSQL();
    virtual void doParse();

public:
    ST_BALANCE_TYPE balance_type;

private:
    int type;
    static string emptySQL;
    static string selectAllSQL;
    vector<ST_BALANCE_TYPE> v_data;
    static string insSQL;
};
#endif
