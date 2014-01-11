#ifndef __BILLRECORDDATA__
#define __BILLRECORDDATA__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class BillRecordData:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_BILL_RECORD_DATA bill_record_data;

private:
    static string insSQL;
};
#endif
