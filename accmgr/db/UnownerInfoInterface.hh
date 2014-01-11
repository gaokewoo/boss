#ifndef __UNOWNERINFOINTERFACE__
#define __UNOWNERINFOINTERFACE__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class UnownerInfoInterface:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_UNOWNER_INFO_INTERFACE unowner_info_interface;

private:
    static string insSQL;
};
#endif
