#ifndef __BALANCERELATIONHIS__
#define __BALANCERELATIONHIS__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class BalanceRelationHis:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_BALANCE_RELATION_HIS balance_relation_his;

private:
    static string insSQL;
};
#endif
