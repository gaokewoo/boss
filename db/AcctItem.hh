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
    ST_ACCT_ITEM getAcctItemByAcctIdServId(long acct_id,long serv_id,long acct_item_type_id,string state);
    void updateStateAndAmountInAcctItemByAcctItemId(long acct_item_id,string state,long amount);
    void updateOtherFeeInAcctItemByAcctItemId(long acct_item_id,long amount,long should_pay,long favour_fee);

public:
    ST_ACCT_ITEM acct_item;

private:
    enum OP_TYPE {INSERT=0,SELECT_BY_ACCT_ID,UPDATE_STATE_AMOUNT,SELECT_BY_ACCT_ID_SERV_ID,UPDATE_OTHER_FEE};
    OP_TYPE type;
    long m_acct_id;
    long m_serv_id;
    long m_acct_item_type_id;
    string m_state;
    long m_acct_item_id;
    long m_amount;
    long m_should_pay;
    long m_favour_fee;
    vector<ST_ACCT_ITEM> v_data;

    string m_ym;
};
#endif
