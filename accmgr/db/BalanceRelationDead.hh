#ifndef __BALANCERELATIONDEAD__
#define __BALANCERELATIONDEAD__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class BalanceRelationDead:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_BALANCE_RELATION_DEAD balance_relation_dead;

private:
    static string insSQL;
};
#endif
