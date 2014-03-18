#ifndef __BALANCESTATE__
#define __BALANCESTATE__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class BalanceState:public SQLInterface
{
public:
    void insertData();
    void emptyData();
    vector<ST_BALANCE_STATE> loadAllData();
    virtual void prepareSQL();
    virtual void doParse();

public:
    ST_BALANCE_STATE balance_state;

private:
    int type;
    static string emptySQL;
    static string selectAllSQL;
    vector<ST_BALANCE_STATE> v_data;
    static string insSQL;
};
#endif
