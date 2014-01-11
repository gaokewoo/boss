#include "SzStatus.hh"

string SzStatus::insSQL="INSERT INTO SZ_STATUS(STATUS,STATUS_NAME,BILL_FLAG,FLAG,STATUS_DESC)VALUES (:STATUS,:STATUS_NAME,:BILL_FLAG,:FLAG,:STATUS_DESC)";

void SzStatus::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void SzStatus::prepareSQL()
{
    stmt->setString(1,sz_status.m_status);
    stmt->setString(2,sz_status.m_status_name);
    stmt->setString(3,sz_status.m_bill_flag);
    stmt->setString(4,sz_status.m_flag);
    stmt->setString(5,sz_status.m_status_desc);
}

