#include "LogoutState.hh"

string LogoutState::insSQL="INSERT INTO LOGOUT_STATE(OWE_STATUS,NAME)VALUES (:OWE_STATUS,:NAME)";

void LogoutState::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void LogoutState::prepareSQL()
{
    stmt->setString(1,logout_state.m_owe_status);
    stmt->setString(2,logout_state.m_name);
}

