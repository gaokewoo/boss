#ifndef __OPENINTERFACE__
#define __OPENINTERFACE__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class OpenInterface:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_OPEN_INTERFACE open_interface;

private:
    static string insSQL;
};
#endif
