#ifndef __INVOICE__
#define __INVOICE__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class Invoice:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_INVOICE invoice;

private:
    static string insSQL;
};
#endif
