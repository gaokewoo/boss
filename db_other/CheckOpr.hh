#ifndef __CHECKOPR__
#define __CHECKOPR__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class CheckOpr:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_CHECK_OPR check_opr;

private:
    static string insSQL;
};
#endif
