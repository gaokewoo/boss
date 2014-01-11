#ifndef __PRESENTINFO__
#define __PRESENTINFO__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class PresentInfo:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_PRESENT_INFO present_info;

private:
    static string insSQL;
};
#endif
