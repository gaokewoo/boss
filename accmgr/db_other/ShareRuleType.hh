#ifndef __SHARERULETYPE__
#define __SHARERULETYPE__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class ShareRuleType:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_SHARE_RULE_TYPE share_rule_type;

private:
    static string insSQL;
};
#endif
