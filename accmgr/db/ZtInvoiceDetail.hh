#ifndef __ZTINVOICEDETAIL__
#define __ZTINVOICEDETAIL__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class ZtInvoiceDetail:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_ZT_INVOICE_DETAIL zt_invoice_detail;

private:
    static string insSQL;
};
#endif
