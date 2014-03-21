#ifndef __ACCT__
#define __ACCT__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class Acct:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse();
    void setAcctOweMinYMAndOweFee(long acct_id,long owe_min_ym,long owe_fee);
    ST_ACCT getAcctByAcctId(long acct_id);

public:
    ST_ACCT acct;

private:
    enum OP_TYPE {INSERT=0,EMPTY,SELECT_BY_ACCT_ID,UPDATE_YM};
    OP_TYPE type;
    static string insSQL;

    long m_owe_min_ym;
    long m_owe_fee;
    long m_acct_id;
};
#endif
