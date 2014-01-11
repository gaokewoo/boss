#ifndef __ACCTUNOWNERINFOHIS__
#define __ACCTUNOWNERINFOHIS__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class AcctUnownerInfoHis:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_ACCT_UNOWNER_INFO_HIS acct_unowner_info_his;

private:
    static string insSQL;
};
#endif
