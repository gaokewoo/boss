#ifndef __OWETASKOBJECTHIS__
#define __OWETASKOBJECTHIS__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class OweTaskObjectHis:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_OWE_TASK_OBJECT_HIS owe_task_object_his;

private:
    static string insSQL;
};
#endif
