#ifndef __ACCTADDACCNBR__
#define __ACCTADDACCNBR__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class AcctAddAccNbr:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_ACCT_ADD_ACC_NBR acct_add_acc_nbr;

private:
    static string insSQL;
};
#endif
