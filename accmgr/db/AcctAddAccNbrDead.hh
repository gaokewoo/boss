#ifndef __ACCTADDACCNBRDEAD__
#define __ACCTADDACCNBRDEAD__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class AcctAddAccNbrDead:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_ACCT_ADD_ACC_NBR_DEAD acct_add_acc_nbr_dead;

private:
    static string insSQL;
};
#endif
