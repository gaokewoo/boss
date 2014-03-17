#ifndef __BILLRECORD__
#define __BILLRECORD__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class BillRecord:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_BILL_RECORD bill_record;

private:
    static string insSQL;
};
#endif
