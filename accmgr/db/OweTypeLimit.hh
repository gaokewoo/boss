#ifndef __OWETYPELIMIT__
#define __OWETYPELIMIT__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class OweTypeLimit:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_OWE_TYPE_LIMIT owe_type_limit;

private:
    static string insSQL;
};
#endif
