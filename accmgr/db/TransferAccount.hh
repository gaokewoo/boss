#ifndef __TRANSFERACCOUNT__
#define __TRANSFERACCOUNT__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class TransferAccount:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_TRANSFER_ACCOUNT transfer_account;

private:
    static string insSQL;
};
#endif
