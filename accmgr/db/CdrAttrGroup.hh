#ifndef __CDRATTRGROUP__
#define __CDRATTRGROUP__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class CdrAttrGroup:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_CDR_ATTR_GROUP cdr_attr_group;

private:
    static string insSQL;
};
#endif
