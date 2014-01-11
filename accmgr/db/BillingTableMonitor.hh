#ifndef __BILLINGTABLEMONITOR__
#define __BILLINGTABLEMONITOR__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class BillingTableMonitor:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_BILLING_TABLE_MONITOR billing_table_monitor;

private:
    static string insSQL;
};
#endif
