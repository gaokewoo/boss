#ifndef __SERVACCT__
#define __SERVACCT__
#include "DBStruct.hh"
#include "SQLInterface.hh"
#include "string.h"

class ServAcct:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse();
    ST_SERV_ACCT getServAcctByServId(long serv_id);

public:
    ST_SERV_ACCT serv_acct;

private:
    enum OP_TYPE{INSERT=0,SELECT_BY_SERV_ID};
    OP_TYPE op_type;
    vector<ST_SERV_ACCT> v_data;
    long m_serv_id;
    static string insSQL;
};
#endif
