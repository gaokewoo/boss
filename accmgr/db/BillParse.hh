#ifndef __BILLPARSE__
#define __BILLPARSE__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class BillParse:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_BILL_PARSE bill_parse;

private:
    static string insSQL;
};
#endif
