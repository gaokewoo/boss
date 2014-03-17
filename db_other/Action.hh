#ifndef __ACTION__
#define __ACTION__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class Action:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_ACTION action;

private:
    static string insSQL;
};
#endif
