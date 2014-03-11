#ifndef __BILLFORMATSELECTORRULE__
#define __BILLFORMATSELECTORRULE__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class BillFormatSelectorRule:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_BILL_FORMAT_SELECTOR_RULE bill_format_selector_rule;

private:
    static string insSQL;
};
#endif
