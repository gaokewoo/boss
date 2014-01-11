#ifndef __INVOICEDETAIL__
#define __INVOICEDETAIL__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class InvoiceDetail:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_INVOICE_DETAIL invoice_detail;

private:
    static string insSQL;
};
#endif
