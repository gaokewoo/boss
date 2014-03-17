#ifndef __USERATTRCHG__
#define __USERATTRCHG__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class UserAttrChg:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_USER_ATTR_CHG user_attr_chg;

private:
    static string insSQL;
};
#endif
