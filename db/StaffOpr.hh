#ifndef __STAFFOPR__
#define __STAFFOPR__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class StaffOpr:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_STAFF_OPR staff_opr;

private:
};
#endif
