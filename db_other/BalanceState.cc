#include "BalanceState.hh"

string BalanceState::insSQL="INSERT INTO BALANCE_STATE(STATE_TYPE,NOTE,TRIG_TYPE)VALUES (:STATE_TYPE,:NOTE,:TRIG_TYPE)";

void BalanceState::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void BalanceState::prepareSQL()
{
    stmt->setString(1,balance_state.m_state_type);
    stmt->setString(2,balance_state.m_note);
    stmt->setString(3,balance_state.m_trig_type);
}

