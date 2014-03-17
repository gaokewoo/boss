#ifndef __CUSTPOSTCHG__
#define __CUSTPOSTCHG__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class CustPostChg:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_CUST_POST_CHG cust_post_chg;

private:
    static string insSQL;
};
#endif
