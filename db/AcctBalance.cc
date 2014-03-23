#include "AcctBalance.hh"

string AcctBalance::insSQL="INSERT INTO ACCT_BALANCE(ACCT_BALANCE_ID,ACCT_ID,BALANCE_TYPE_ID,BALANCE,RESERVE_BALANCE,CYCLE_UPPER,CYCLE_LOWER,CYCLE_UPPER_TYPE,CYCLE_LOWER_TYPE,PAYMENT_DATE,BILL_MONTH_FLAG,EFF_DATE,EXP_DATE,STATE,STATE_DATE)VALUES (:ACCT_BALANCE_ID,:ACCT_ID,:BALANCE_TYPE_ID,:BALANCE,:RESERVE_BALANCE,:CYCLE_UPPER,:CYCLE_LOWER,:CYCLE_UPPER_TYPE,:CYCLE_LOWER_TYPE,SYSDATE,:BILL_MONTH_FLAG,SYSDATE,SYSDATE+3650,:STATE,SYSDATE)";

void AcctBalance::insertData()
{
    type=INSERT;
    setSQL(insSQL);
    executeUpdate();
}

vector<ST_ACCT_BALANCE> AcctBalance::getAcctBalanceByAcctId(long acct_id)
{
    type=SELECT_BY_ACCT_ID;
    m_acct_id=acct_id;
    setSQL("SELECT ACCT_BALANCE_ID,ACCT_ID,BALANCE_TYPE_ID,BALANCE,RESERVE_BALANCE,CYCLE_UPPER,CYCLE_LOWER,CYCLE_UPPER_TYPE,CYCLE_LOWER_TYPE,TO_CHAR(PAYMENT_DATE,'YYYYMMDDHH24MISS'),BILL_MONTH_FLAG,TO_CHAR(EFF_DATE,'YYYYMMDDHH24MISS'),TO_CHAR(EXP_DATE,'YYYYMMDDHH24MISS'),STATE,TO_CHAR(STATE_DATE,'YYYYMMDDHH24MISS') FROM ACCT_BALANCE WHERE ACCT_ID=:ACCT_ID");
    executeQuery();

    return v_data;
}

void AcctBalance::deleteAcctBalanceByAcctBalanceId(long acct_balance_id)
{
    type=DELETE;
    m_acct_balance_id = acct_balance_id;

    setSQL("INSERT INTO ACCT_BALANCE_HIS"
                "(ACCT_BALANCE_ID,ACCT_ID,BALANCE_TYPE_ID,BALANCE,RESERVE_BALANCE,"
                "CYCLE_UPPER,CYCLE_LOWER,CYCLE_UPPER_TYPE,CYCLE_LOWER_TYPE,PAYMENT_DATE,"
                "BILL_MONTH_FLAG,EFF_DATE,EXP_DATE,STATE,STATE_DATE,HIS_DATE)"
                "SELECT ACCT_BALANCE_ID,ACCT_ID,BALANCE_TYPE_ID,BALANCE,RESERVE_BALANCE,"
                "CYCLE_UPPER,CYCLE_LOWER,CYCLE_UPPER_TYPE,CYCLE_LOWER_TYPE,PAYMENT_DATE,"
                "BILL_MONTH_FLAG,EFF_DATE,EXP_DATE,STATE,STATE_DATE,SYSDATE "
                "FROM ACCT_BALANCE WHERE ACCT_BALANCE_ID=:ACCT_BALANCE_ID");
    executeUpdate();

    setSQL("DELETE FROM ACCT_BALANCE WHERE ACCT_BALANCE_ID=:ACCT_BALANCE_ID");
    executeUpdate();
}

void AcctBalance::updateAcctBalanceByAcctBalanceId(long acct_balance_id,long balance)
{
    type=UPDATE;
    m_acct_balance_id = acct_balance_id;
    m_balance = balance;

    setSQL("UPDATE ACCT_BALANCE SET BALANCE=:BALANCE WHERE ACCT_BALANCE_ID=:ACCT_BALANCE_ID");

    executeUpdate();
}

void AcctBalance::doParse()
{
    acct_balance.m_acct_balance_id = (long)rset->getNumber(1);
    acct_balance.m_acct_id = (long)rset->getNumber(2);
    acct_balance.m_balance_type_id = (long)rset->getNumber(3);
    acct_balance.m_balance = (long)rset->getNumber(4);
    acct_balance.m_reserve_balance = (long)rset->getNumber(5);
    acct_balance.m_cycle_upper = (long)rset->getNumber(6);
    acct_balance.m_cycle_lower = (long)rset->getNumber(7);
    acct_balance.m_cycle_upper_type = rset->getString(8);
    acct_balance.m_cycle_lower_type = rset->getString(9);
    acct_balance.m_payment_date = rset->getString(10);
    acct_balance.m_bill_month_flag = rset->getString(11);
    acct_balance.m_eff_date = rset->getString(12);
    acct_balance.m_exp_date = rset->getString(13);
    acct_balance.m_state = rset->getString(14);
    acct_balance.m_state_date = rset->getString(15);

    v_data.push_back(acct_balance);
}

void AcctBalance::prepareSQL()
{
    if (type == INSERT)
    {
        stmt->setNumber(1,acct_balance.m_acct_balance_id);
        stmt->setNumber(2,acct_balance.m_acct_id);
        stmt->setNumber(3,acct_balance.m_balance_type_id);
        stmt->setNumber(4,acct_balance.m_balance);
        stmt->setNumber(5,acct_balance.m_reserve_balance);
        stmt->setNumber(6,acct_balance.m_cycle_upper);
        stmt->setNumber(7,acct_balance.m_cycle_lower);
        stmt->setString(8,acct_balance.m_cycle_upper_type);
        stmt->setString(9,acct_balance.m_cycle_lower_type);
        stmt->setString(10,acct_balance.m_bill_month_flag);
        stmt->setString(11,acct_balance.m_state);
    }
    else if (type == SELECT_BY_ACCT_ID)
    {
        stmt->setNumber(1,m_acct_id);
    }
    else if (type == DELETE)
    {
        stmt->setNumber(1,m_acct_balance_id);
    }
    else if (type == UPDATE)
    {
        stmt->setNumber(1,m_balance);
        stmt->setNumber(2,m_acct_balance_id);
    }
}

