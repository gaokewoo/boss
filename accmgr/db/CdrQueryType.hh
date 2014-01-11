#ifndef __CDRQUERYTYPE__
#define __CDRQUERYTYPE__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class CdrQueryType:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_CDR_QUERY_TYPE cdr_query_type;

private:
    static string insSQL;
};
#endif
