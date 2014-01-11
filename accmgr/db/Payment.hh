#ifndef __PAYMENT__
#define __PAYMENT__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class Payment:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_PAYMENT payment;

private:
    static string insSQL;
};
#endif
