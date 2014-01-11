#ifndef __BILLREMARK__
#define __BILLREMARK__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class BillRemark:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_BILL_REMARK bill_remark;

private:
    static string insSQL;
};
#endif
