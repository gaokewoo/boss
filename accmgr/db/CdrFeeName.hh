#ifndef __CDRFEENAME__
#define __CDRFEENAME__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class CdrFeeName:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_CDR_FEE_NAME cdr_fee_name;

private:
    static string insSQL;
};
#endif
