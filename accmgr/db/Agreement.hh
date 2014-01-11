#ifndef __AGREEMENT__
#define __AGREEMENT__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class Agreement:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_AGREEMENT agreement;

private:
    static string insSQL;
};
#endif
