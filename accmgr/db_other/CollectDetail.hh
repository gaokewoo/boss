#ifndef __COLLECTDETAIL__
#define __COLLECTDETAIL__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class CollectDetail:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_COLLECT_DETAIL collect_detail;

private:
    static string insSQL;
};
#endif
