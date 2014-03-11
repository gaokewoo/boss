#ifndef __PAYINTERFACE__
#define __PAYINTERFACE__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class PayInterface:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_PAY_INTERFACE pay_interface;

private:
    static string insSQL;
};
#endif
