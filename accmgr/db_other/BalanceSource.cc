#include "BalanceSource.hh"

string BalanceSource::insSQL="INSERT INTO BALANCE_SOURCE(OPER_INCOME_ID,PAYMENT_ID,ACCT_BALANCE_ID,OPER_TYPE,STAFF_ID,OPER_DATE,AMOUNT,CUR_AMOUNT,BALANCE_RELATION_ID,BALANCE_SOURCE_ID,ALLOW_DRAW,INV_OFFER,CUR_STATUS,CUR_STATUS_DATE,STATE_DATE,STATE)VALUES (:OPER_INCOME_ID,:PAYMENT_ID,:ACCT_BALANCE_ID,:OPER_TYPE,:STAFF_ID,SYSDATE,:AMOUNT,:CUR_AMOUNT,:BALANCE_RELATION_ID,:BALANCE_SOURCE_ID,:ALLOW_DRAW,:INV_OFFER,:CUR_STATUS,SYSDATE,SYSDATE,:STATE)";

void BalanceSource::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void BalanceSource::prepareSQL()
{
    stmt->setNumber(1,balance_source.m_oper_income_id);
    stmt->setNumber(2,balance_source.m_payment_id);
    stmt->setNumber(3,balance_source.m_acct_balance_id);
    stmt->setString(4,balance_source.m_oper_type);
    stmt->setNumber(5,balance_source.m_staff_id);
    stmt->setNumber(6,balance_source.m_amount);
    stmt->setNumber(7,balance_source.m_cur_amount);
    stmt->setNumber(8,balance_source.m_balance_relation_id);
    stmt->setNumber(9,balance_source.m_balance_source_id);
    stmt->setString(10,balance_source.m_allow_draw);
    stmt->setString(11,balance_source.m_inv_offer);
    stmt->setString(12,balance_source.m_cur_status);
    stmt->setString(13,balance_source.m_state);
}

