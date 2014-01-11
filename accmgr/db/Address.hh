#ifndef __ADDRESS__
#define __ADDRESS__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class Address:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_ADDRESS address;

private:
    static string insSQL;
};
#endif
