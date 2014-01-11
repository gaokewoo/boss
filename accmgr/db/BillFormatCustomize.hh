#ifndef __BILLFORMATCUSTOMIZE__
#define __BILLFORMATCUSTOMIZE__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class BillFormatCustomize:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_BILL_FORMAT_CUSTOMIZE bill_format_customize;

private:
    static string insSQL;
};
#endif
