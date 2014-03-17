#ifndef __BILLUNOWNERINFOHIS__
#define __BILLUNOWNERINFOHIS__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class BillUnownerInfoHis:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_BILL_UNOWNER_INFO_HIS bill_unowner_info_his;

private:
    static string insSQL;
};
#endif
