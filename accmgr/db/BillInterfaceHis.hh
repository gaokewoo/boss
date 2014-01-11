#ifndef __BILLINTERFACEHIS__
#define __BILLINTERFACEHIS__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class BillInterfaceHis:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_BILL_INTERFACE_HIS bill_interface_his;

private:
    static string insSQL;
};
#endif
