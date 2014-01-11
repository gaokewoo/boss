#ifndef __BANK__
#define __BANK__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class Bank:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_BANK bank;

private:
    static string insSQL;
};
#endif
