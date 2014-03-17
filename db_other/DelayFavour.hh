#ifndef __DELAYFAVOUR__
#define __DELAYFAVOUR__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class DelayFavour:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_DELAY_FAVOUR delay_favour;

private:
    static string insSQL;
};
#endif
