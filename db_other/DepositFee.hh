#ifndef __DEPOSITFEE__
#define __DEPOSITFEE__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class DepositFee:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_DEPOSIT_FEE deposit_fee;

private:
    static string insSQL;
};
#endif
