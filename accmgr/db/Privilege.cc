#include "Privilege.hh"

string Privilege::insSQL="INSERT INTO PRIVILEGE(PRIVILEGE_ID,PARENT_PRIVILEGEID,PRIVILEGE_NAME,PRIVILEGE_TYPE,APP_CODE,PRIVILEGE_DESC)VALUES (:PRIVILEGE_ID,:PARENT_PRIVILEGEID,:PRIVILEGE_NAME,:PRIVILEGE_TYPE,:APP_CODE,:PRIVILEGE_DESC)";

string Privilege::emptySQL="DELETE FROM PRIVILEGE";

string Privilege::selectAllSQL="SELECT PRIVILEGE_ID,PARENT_PRIVILEGEID,PRIVILEGE_NAME,PRIVILEGE_TYPE,APP_CODE,PRIVILEGE_DESC FROM PRIVILEGE";

void Privilege::insertData()
{
    type=0;
    setSQL(insSQL);
    executeUpdate();
}

void Privilege::emptyData()
{
    type=1;
    setSQL(emptySQL);
    executeUpdate();
}

vector<ST_PRIVILEGE> Privilege::loadAllData()
{
    type=2;
    setSQL(selectAllSQL);
    executeQuery();

    return v_data;
}

void Privilege::doParse()
{
    privilege.m_privilege_id = (long)rset->getNumber(1);
    privilege.m_parent_privilegeid = (long)rset->getNumber(2);
    privilege.m_privilege_name = rset->getString(3);
    privilege.m_privilege_type = rset->getString(4);
    privilege.m_app_code = rset->getString(5);
    privilege.m_privilege_desc = rset->getString(6);

    v_data.push_back(privilege);
}

void Privilege::prepareSQL()
{
    if (type == 0)
    {
    stmt->setNumber(1,privilege.m_privilege_id);
    stmt->setNumber(2,privilege.m_parent_privilegeid);
    stmt->setString(3,privilege.m_privilege_name);
    stmt->setString(4,privilege.m_privilege_type);
    stmt->setString(5,privilege.m_app_code);
    stmt->setString(6,privilege.m_privilege_desc);
    }
}

