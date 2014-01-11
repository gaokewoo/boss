#ifndef __BILLFORMATSELECTOR__
#define __BILLFORMATSELECTOR__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class BillFormatSelector:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_BILL_FORMAT_SELECTOR bill_format_selector;

private:
    static string insSQL;
};
#endif
