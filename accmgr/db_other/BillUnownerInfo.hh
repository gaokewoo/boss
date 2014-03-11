#ifndef __BILLUNOWNERINFO__
#define __BILLUNOWNERINFO__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class BillUnownerInfo:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_BILL_UNOWNER_INFO bill_unowner_info;

private:
    static string insSQL;
};
#endif
