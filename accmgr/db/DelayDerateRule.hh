#ifndef __DELAYDERATERULE__
#define __DELAYDERATERULE__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class DelayDerateRule:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_DELAY_DERATE_RULE delay_derate_rule;

private:
    static string insSQL;
};
#endif
