#ifndef __PAYINFO__
#define __PAYINFO__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class PayInfo:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_PAY_INFO pay_info;

private:
    static string insSQL;
};
#endif
