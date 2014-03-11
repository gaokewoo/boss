#ifndef __COLLECTOPRT__
#define __COLLECTOPRT__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class CollectOprt:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_COLLECT_OPRT collect_oprt;

private:
    static string insSQL;
};
#endif
