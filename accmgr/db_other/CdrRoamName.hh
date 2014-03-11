#ifndef __CDRROAMNAME__
#define __CDRROAMNAME__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class CdrRoamName:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_CDR_ROAM_NAME cdr_roam_name;

private:
    static string insSQL;
};
#endif
