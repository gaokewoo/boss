#ifndef __CUSTIDENTIFICATION__
#define __CUSTIDENTIFICATION__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class CustIdentification:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_CUST_IDENTIFICATION cust_identification;

private:
    static string insSQL;
};
#endif
