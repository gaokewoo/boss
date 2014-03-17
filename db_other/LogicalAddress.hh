#ifndef __LOGICALADDRESS__
#define __LOGICALADDRESS__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class LogicalAddress:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_LOGICAL_ADDRESS logical_address;

private:
    static string insSQL;
};
#endif
