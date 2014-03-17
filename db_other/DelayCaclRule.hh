#ifndef __DELAYCACLRULE__
#define __DELAYCACLRULE__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class DelayCaclRule:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_DELAY_CACL_RULE delay_cacl_rule;

private:
    static string insSQL;
};
#endif
