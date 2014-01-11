#ifndef __OWETASK__
#define __OWETASK__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class OweTask:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_OWE_TASK owe_task;

private:
    static string insSQL;
};
#endif
