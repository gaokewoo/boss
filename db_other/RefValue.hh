#ifndef __REFVALUE__
#define __REFVALUE__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class RefValue:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_REF_VALUE ref_value;

private:
    static string insSQL;
};
#endif
