#include "Action.hh"

string Action::insSQL="INSERT INTO ACTION(ACTION_ID,ACTION_TYPE_ID,ACTION_NAME)VALUES (:ACTION_ID,:ACTION_TYPE_ID,:ACTION_NAME)";

void Action::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void Action::prepareSQL()
{
    stmt->setNumber(1,action.m_action_id);
    stmt->setNumber(2,action.m_action_type_id);
    stmt->setString(3,action.m_action_name);
}

