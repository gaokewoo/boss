#ifndef __ACCTBALANCE__
#define __ACCTBALANCE__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class AcctBalance:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse();
    vector<ST_ACCT_BALANCE> getAcctBalanceByAcctId(long acct_id);
    void deleteAcctBalanceByAcctBalanceId(long acct_balance_id);
    void updateAcctBalanceByAcctBalanceId(long acct_balance_id,long balance);

public:
    ST_ACCT_BALANCE acct_balance;

private:
    enum OP_TYPE {INSERT=0,SELECT_BY_ACCT_ID,DELETE,UPDATE};
    OP_TYPE type;
    long m_acct_id;
    long m_acct_balance_id;
    long m_balance;
    vector<ST_ACCT_BALANCE> v_data;
    static string insSQL;
};
#endif
