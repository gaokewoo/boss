#ifndef __OWESTOPINTERFACE__
#define __OWESTOPINTERFACE__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class OweStopInterface:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_OWE_STOP_INTERFACE owe_stop_interface;

private:
    static string insSQL;
};
#endif
