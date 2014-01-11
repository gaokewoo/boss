#ifndef __SERVATTRTYPE__
#define __SERVATTRTYPE__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class ServAttrType:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_SERV_ATTR_TYPE serv_attr_type;

private:
    static string insSQL;
};
#endif
