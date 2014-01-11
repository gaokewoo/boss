#ifndef __BILL__
#define __BILL__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class Bill:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_BILL bill;

private:
    static string insSQL;
};
#endif
