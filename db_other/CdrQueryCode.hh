#ifndef __CDRQUERYCODE__
#define __CDRQUERYCODE__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class CdrQueryCode:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_CDR_QUERY_CODE cdr_query_code;

private:
    static string insSQL;
};
#endif
