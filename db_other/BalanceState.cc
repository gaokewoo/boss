#include "BalanceState.hh"

string BalanceState::insSQL="INSERT INTO BALANCE_STATE(STATE_TYPE,NOTE,TRIG_TYPE)VALUES (:STATE_TYPE,:NOTE,:TRIG_TYPE)";

string BalanceState::emptySQL="DELETE FROM BALANCE_STATE";

string BalanceState::selectAllSQL="SELECT STATE_TYPE,NOTE,TRIG_TYPE FROM BALANCE_STATE";

void BalanceState::insertData()
{
    type=0;
    setSQL(insSQL);
    executeUpdate();
}

void BalanceState::emptyData()
{
    type=1;
    setSQL(emptySQL);
    executeUpdate();
}

vector<ST_BALANCE_STATE> BalanceState::loadAllData()
{
    type=2;
    setSQL(selectAllSQL);
    executeQuery();

    return v_data;
}

void BalanceState::doParse()
{
    balance_state.m_state_type = rset->getString(1);
    balance_state.m_note = rset->getString(2);
    balance_state.m_trig_type = rset->getString(3);

    v_data.push_back(balance_state);
}

void BalanceState::prepareSQL()
{
    if (type == 0)
    {
    stmt->setString(1,balance_state.m_state_type);
    stmt->setString(2,balance_state.m_note);
    stmt->setString(3,balance_state.m_trig_type);
    }
}

