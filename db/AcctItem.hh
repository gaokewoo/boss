#ifndef __ACCTITEM__
#define __ACCTITEM__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class AcctItem:public SQLInterface
{
public:
    AcctItem();
    void insertData();
    virtual void prepareSQL();
    virtual void doParse();
    void setYM(string ym){m_ym = ym;}
    vector<ST_ACCT_ITEM> getAcctItemByAcctId(long acct_id);
    void updateStateAndAmountInAcctItemByAcctItemId(long acct_item_id,string state,long amount);

public:
    ST_ACCT_ITEM acct_item;

private:
    enum OP_TYPE {INSERT=0,SELECT_BY_ACCT_ID,UPDATE_STATE_AMOUNT};
    OP_TYPE type;
    long m_acct_id;
    string m_state;
    long m_acct_item_id;
    long m_amount;
    vector<ST_ACCT_ITEM> v_data;

    string m_ym;
};
#endif
