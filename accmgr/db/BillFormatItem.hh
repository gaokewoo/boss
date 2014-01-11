#ifndef __BILLFORMATITEM__
#define __BILLFORMATITEM__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class BillFormatItem:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_BILL_FORMAT_ITEM bill_format_item;

private:
    static string insSQL;
};
#endif
