#ifndef __BILLFORMAT__
#define __BILLFORMAT__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class BillFormat:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_BILL_FORMAT bill_format;

private:
    static string insSQL;
};
#endif
