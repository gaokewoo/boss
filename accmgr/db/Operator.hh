#ifndef __OPERATOR__
#define __OPERATOR__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class Operator:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_OPERATOR oper;

private:
    static string insSQL;
};
#endif
