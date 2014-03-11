#include "PhoneComm.hh"

string PhoneComm::insSQL="INSERT INTO PHONE_COMM(PHONE_HEAD,REGION_CODE,DEAL_TIME,DEAL_FLAG)VALUES (:PHONE_HEAD,:REGION_CODE,SYSDATE,:DEAL_FLAG)";

void PhoneComm::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void PhoneComm::prepareSQL()
{
    stmt->setString(1,phone_comm.m_phone_head);
    stmt->setString(2,phone_comm.m_region_code);
    stmt->setString(3,phone_comm.m_deal_flag);
}

