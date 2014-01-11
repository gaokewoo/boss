#ifndef __LOGOUTSTATE__
#define __LOGOUTSTATE__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class LogoutState:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_LOGOUT_STATE logout_state;

private:
    static string insSQL;
};
#endif
