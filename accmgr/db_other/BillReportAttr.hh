#ifndef __BILLREPORTATTR__
#define __BILLREPORTATTR__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class BillReportAttr:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_BILL_REPORT_ATTR bill_report_attr;

private:
    static string insSQL;
};
#endif
