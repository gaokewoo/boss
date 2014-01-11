#ifndef __PRIVILEGE__
#define __PRIVILEGE__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class Privilege:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_PRIVILEGE privilege;

private:
    static string insSQL;
};
#endif
