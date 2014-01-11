#include "MmdbAcctBalanceInc.hh"

string MmdbAcctBalanceInc::insSQL="INSERT INTO MMDB_ACCT_BALANCE_INC(OP_SN,OP_TYPE,OP_TIME,ACCT_BALANCE_ID,ACCT_ID,BALANCE_TYPE_ID,BALANCE,RESERVE_BALANCE,CYCLE_UPPER,CYCLE_LOWER,CYCLE_UPPER_TYPE,CYCLE_LOWER_TYPE,PAYMENT_DATE,BILL_MONTH_FLAG,EFF_DATE,EXP_DATE,STATE,STATE_DATE)VALUES (:OP_SN,:OP_TYPE,SYSDATE,:ACCT_BALANCE_ID,:ACCT_ID,:BALANCE_TYPE_ID,:BALANCE,:RESERVE_BALANCE,:CYCLE_UPPER,:CYCLE_LOWER,:CYCLE_UPPER_TYPE,:CYCLE_LOWER_TYPE,SYSDATE,:BILL_MONTH_FLAG,SYSDATE,SYSDATE,:STATE,SYSDATE)";

void MmdbAcctBalanceInc::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void MmdbAcctBalanceInc::prepareSQL()
{
    stmt->setNumber(1,mmdb_acct_balance_inc.m_op_sn);
    stmt->setString(2,mmdb_acct_balance_inc.m_op_type);
    stmt->setNumber(3,mmdb_acct_balance_inc.m_acct_balance_id);
    stmt->setNumber(4,mmdb_acct_balance_inc.m_acct_id);
    stmt->setNumber(5,mmdb_acct_balance_inc.m_balance_type_id);
    stmt->setNumber(6,mmdb_acct_balance_inc.m_balance);
    stmt->setNumber(7,mmdb_acct_balance_inc.m_reserve_balance);
    stmt->setNumber(8,mmdb_acct_balance_inc.m_cycle_upper);
    stmt->setNumber(9,mmdb_acct_balance_inc.m_cycle_lower);
    stmt->setString(10,mmdb_acct_balance_inc.m_cycle_upper_type);
    stmt->setString(11,mmdb_acct_balance_inc.m_cycle_lower_type);
    stmt->setString(12,mmdb_acct_balance_inc.m_bill_month_flag);
    stmt->setString(13,mmdb_acct_balance_inc.m_state);
}

