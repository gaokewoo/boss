#include "Staff.hh"

string Staff::insSQL="INSERT INTO STAFF(STAFF_ID,OPERATE_ORG_ID,STAFF_CODE,PASSWD,SCOPE_LEVEL,STAFF_DESC,PARENT_PARTYROLEID,STAFF_TYPE)VALUES (:STAFF_ID,:OPERATE_ORG_ID,:STAFF_CODE,:PASSWD,:SCOPE_LEVEL,:STAFF_DESC,:PARENT_PARTYROLEID,:STAFF_TYPE)";

string Staff::emptySQL="DELETE FROM STAFF";

string Staff::selectAllSQL="SELECT STAFF_ID,OPERATE_ORG_ID,STAFF_CODE,PASSWD,SCOPE_LEVEL,STAFF_DESC,PARENT_PARTYROLEID,STAFF_TYPE FROM STAFF";

void Staff::insertData()
{
    type=0;
    setSQL(insSQL);
    executeUpdate();
}

void Staff::emptyData()
{
    type=1;
    setSQL(emptySQL);
    executeUpdate();
}

vector<ST_STAFF> Staff::loadAllData()
{
    type=2;
    setSQL(selectAllSQL);
    executeQuery();

    return v_data;
}

void Staff::doParse()
{
    staff.m_staff_id = (long)rset->getNumber(1);
    staff.m_operate_org_id = (long)rset->getNumber(2);
    staff.m_staff_code = rset->getString(3);
    staff.m_passwd = rset->getString(4);
    staff.m_scope_level = rset->getString(5);
    staff.m_staff_desc = rset->getString(6);
    staff.m_parent_partyroleid = (long)rset->getNumber(7);
    staff.m_staff_type = rset->getString(8);

    v_data.push_back(staff);
}

void Staff::prepareSQL()
{
    if (type == 0)
    {
    stmt->setNumber(1,staff.m_staff_id);
    stmt->setNumber(2,staff.m_operate_org_id);
    stmt->setString(3,staff.m_staff_code);
    stmt->setString(4,staff.m_passwd);
    stmt->setString(5,staff.m_scope_level);
    stmt->setString(6,staff.m_staff_desc);
    stmt->setNumber(7,staff.m_parent_partyroleid);
    stmt->setString(8,staff.m_staff_type);
    }
}

