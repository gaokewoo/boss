#ifndef __MEASUREMETHOD__
#define __MEASUREMETHOD__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class MeasureMethod:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_MEASURE_METHOD measure_method;

private:
    static string insSQL;
};
#endif
