#ifndef __PAYINTERFACEHIS__
#define __PAYINTERFACEHIS__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class PayInterfaceHis:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_PAY_INTERFACE_HIS pay_interface_his;

private:
    static string insSQL;
};
#endif
