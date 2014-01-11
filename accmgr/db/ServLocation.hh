#ifndef __SERVLOCATION__
#define __SERVLOCATION__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class ServLocation:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_SERV_LOCATION serv_location;

private:
    static string insSQL;
};
#endif
