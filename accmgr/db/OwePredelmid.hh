#ifndef __OWEPREDELMID__
#define __OWEPREDELMID__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class OwePredelmid:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_OWE_PREDELMID owe_predelmid;

private:
    static string insSQL;
};
#endif
