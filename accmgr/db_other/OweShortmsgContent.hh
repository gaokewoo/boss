#ifndef __OWESHORTMSGCONTENT__
#define __OWESHORTMSGCONTENT__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class OweShortmsgContent:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_OWE_SHORTMSG_CONTENT owe_shortmsg_content;

private:
    static string insSQL;
};
#endif
