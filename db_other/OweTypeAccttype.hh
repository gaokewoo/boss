#ifndef __OWETYPEACCTTYPE__
#define __OWETYPEACCTTYPE__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class OweTypeAccttype:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_OWE_TYPE_ACCTTYPE owe_type_accttype;

private:
    static string insSQL;
};
#endif
