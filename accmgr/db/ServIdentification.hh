#ifndef __SERVIDENTIFICATION__
#define __SERVIDENTIFICATION__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class ServIdentification:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_SERV_IDENTIFICATION serv_identification;

private:
    static string insSQL;
};
#endif
