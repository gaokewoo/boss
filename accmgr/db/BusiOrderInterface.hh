#ifndef __BUSIORDERINTERFACE__
#define __BUSIORDERINTERFACE__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class BusiOrderInterface:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_BUSI_ORDER_INTERFACE busi_order_interface;

private:
    static string insSQL;
};
#endif
