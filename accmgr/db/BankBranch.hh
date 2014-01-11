#ifndef __BANKBRANCH__
#define __BANKBRANCH__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class BankBranch:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_BANK_BRANCH bank_branch;

private:
    static string insSQL;
};
#endif
