#ifndef __OWETOTALSHORTMSG__
#define __OWETOTALSHORTMSG__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class OweTotalShortMsg:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_OWE_TOTAL_SHORT_MSG owe_total_short_msg;

private:
    static string insSQL;
};
#endif
