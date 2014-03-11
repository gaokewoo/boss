#ifndef __OWETASKOBJECT__
#define __OWETASKOBJECT__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class OweTaskObject:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_OWE_TASK_OBJECT owe_task_object;

private:
    static string insSQL;
};
#endif
