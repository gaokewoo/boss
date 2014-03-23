#include "BalancePayout.hh"
#include "Dual.hh"


void BalancePayout::insertData()
{
    Dual dual;
    dual.setConnection(conn);
    string m_ym = dual.getSysDateYYYYMM();

    string insSQL="INSERT INTO BALANCE_PAYOUT"+m_ym+"(OPER_PAYOUT_ID,ACCT_BALANCE_ID,BILLING_CYCLE_ID,BILL_ID,OPER_TYPE,OPER_DATE,AMOUNT,BALANCE,PRN_COUNT,BALANCE_RELATION_ID,STAFF_ID,STATE,STATE_DATE)VALUES (:OPER_PAYOUT_ID,:ACCT_BALANCE_ID,:BILLING_CYCLE_ID,:BILL_ID,:OPER_TYPE,SYSDATE,:AMOUNT,:BALANCE,:PRN_COUNT,:BALANCE_RELATION_ID,:STAFF_ID,:STATE,SYSDATE)";
    setSQL(insSQL);
    executeUpdate();
}

void BalancePayout::prepareSQL()
{
    stmt->setNumber(1,balance_payout.m_oper_payout_id);
    stmt->setNumber(2,balance_payout.m_acct_balance_id);
    stmt->setNumber(3,balance_payout.m_billing_cycle_id);
    stmt->setNumber(4,balance_payout.m_bill_id);
    stmt->setString(5,balance_payout.m_oper_type);
    stmt->setNumber(6,balance_payout.m_amount);
    stmt->setNumber(7,balance_payout.m_balance);
    stmt->setNumber(8,balance_payout.m_prn_count);
    stmt->setNumber(9,balance_payout.m_balance_relation_id);
    stmt->setNumber(10,balance_payout.m_staff_id);
    stmt->setString(11,balance_payout.m_state);
}

