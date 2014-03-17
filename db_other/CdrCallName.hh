#ifndef __CDRCALLNAME__
#define __CDRCALLNAME__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class CdrCallName:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_CDR_CALL_NAME cdr_call_name;

private:
    static string insSQL;
};
#endif
