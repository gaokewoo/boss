#ifndef __BILLUNOWNERCHG__
#define __BILLUNOWNERCHG__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class BillUnownerChg:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_BILL_UNOWNER_CHG bill_unowner_chg;

private:
    static string insSQL;
};
#endif
