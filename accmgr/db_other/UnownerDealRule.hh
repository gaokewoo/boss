#ifndef __UNOWNERDEALRULE__
#define __UNOWNERDEALRULE__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class UnownerDealRule:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_UNOWNER_DEAL_RULE unowner_deal_rule;

private:
    static string insSQL;
};
#endif
