#ifndef __COMMONSHORTCJ__
#define __COMMONSHORTCJ__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class CommonShortCj:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_COMMON_SHORT_CJ common_short_cj;

private:
    static string insSQL;
};
#endif
