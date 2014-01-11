#ifndef __OWEDATETYPE__
#define __OWEDATETYPE__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class OweDateType:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_OWE_DATE_TYPE owe_date_type;

private:
    static string insSQL;
};
#endif
