#ifndef __PERSONALOWESCHEME__
#define __PERSONALOWESCHEME__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class PersonalOweScheme:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_PERSONAL_OWE_SCHEME personal_owe_scheme;

private:
    static string insSQL;
};
#endif
