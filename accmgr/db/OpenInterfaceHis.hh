#ifndef __OPENINTERFACEHIS__
#define __OPENINTERFACEHIS__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class OpenInterfaceHis:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_OPEN_INTERFACE_HIS open_interface_his;

private:
    static string insSQL;
};
#endif
