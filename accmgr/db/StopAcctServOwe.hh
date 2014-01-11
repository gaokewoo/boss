#ifndef __STOPACCTSERVOWE__
#define __STOPACCTSERVOWE__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class StopAcctServOwe:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_STOP_ACCT_SERV_OWE stop_acct_serv_owe;

private:
    static string insSQL;
};
#endif
