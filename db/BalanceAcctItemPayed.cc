#include "BalanceAcctItemPayed.hh"
#include "Dual.hh"


void BalanceAcctItemPayed::insertData()
{
    Dual dual;
    dual.setConnection(conn);
    string m_ym = dual.getSysDateYYYYMM();

    string insSQL="INSERT INTO BALANCE_ACCT_ITEM_PAYED"+m_ym+"(OPER_PAYOUT_ID,ACCT_ITEM_ID,BALANCE,SERV_ID,ACCT_ITEM_TYPE_ID,ITEM_SOURCE_ID,STATE,STATE_DATE)VALUES (:OPER_PAYOUT_ID,:ACCT_ITEM_ID,:BALANCE,:SERV_ID,:ACCT_ITEM_TYPE_ID,:ITEM_SOURCE_ID,:STATE,SYSDATE)";

    setSQL(insSQL);
    executeUpdate();
}

void BalanceAcctItemPayed::prepareSQL()
{
    stmt->setNumber(1,balance_acct_item_payed.m_oper_payout_id);
    stmt->setNumber(2,balance_acct_item_payed.m_acct_item_id);
    stmt->setNumber(3,balance_acct_item_payed.m_balance);
    stmt->setNumber(4,balance_acct_item_payed.m_serv_id);
    stmt->setNumber(5,balance_acct_item_payed.m_acct_item_type_id);
    stmt->setNumber(6,balance_acct_item_payed.m_item_source_id);
    stmt->setString(7,balance_acct_item_payed.m_state);
}

