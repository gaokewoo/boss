#ifndef __ACCTADDACCNBRHIS__
#define __ACCTADDACCNBRHIS__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class AcctAddAccNbrHis:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_ACCT_ADD_ACC_NBR_HIS acct_add_acc_nbr_his;

private:
    static string insSQL;
};
#endif
