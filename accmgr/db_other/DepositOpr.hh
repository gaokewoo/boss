#ifndef __DEPOSITOPR__
#define __DEPOSITOPR__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class DepositOpr:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_DEPOSIT_OPR deposit_opr;

private:
    static string insSQL;
};
#endif
