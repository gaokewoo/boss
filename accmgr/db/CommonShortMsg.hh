#ifndef __COMMONSHORTMSG__
#define __COMMONSHORTMSG__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class CommonShortMsg:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_COMMON_SHORT_MSG common_short_msg;

private:
    static string insSQL;
};
#endif
