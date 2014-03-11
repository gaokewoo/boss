#ifndef __OWESHORTMSGCODE__
#define __OWESHORTMSGCODE__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class OweShortmsgCode:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_OWE_SHORTMSG_CODE owe_shortmsg_code;

private:
    static string insSQL;
};
#endif
