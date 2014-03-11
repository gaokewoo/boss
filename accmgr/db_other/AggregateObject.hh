#ifndef __AGGREGATEOBJECT__
#define __AGGREGATEOBJECT__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class AggregateObject:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_AGGREGATE_OBJECT aggregate_object;

private:
    static string insSQL;
};
#endif
