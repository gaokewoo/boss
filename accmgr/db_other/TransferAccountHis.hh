#ifndef __TRANSFERACCOUNTHIS__
#define __TRANSFERACCOUNTHIS__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class TransferAccountHis:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_TRANSFER_ACCOUNT_HIS transfer_account_his;

private:
    static string insSQL;
};
#endif
