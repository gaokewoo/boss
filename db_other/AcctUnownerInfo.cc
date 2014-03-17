#include "AcctUnownerInfo.hh"

string AcctUnownerInfo::insSQL="INSERT INTO ACCT_UNOWNER_INFO(ACC_NBR,ITEM_SOURCE_ID,ACCT_ITEM_TYPE_ID,REGION_CODE,UNOWNER_FEE,INSERT_TIME,STATE,STATE_DATE)VALUES (:ACC_NBR,:ITEM_SOURCE_ID,:ACCT_ITEM_TYPE_ID,:REGION_CODE,:UNOWNER_FEE,SYSDATE,:STATE,SYSDATE)";

void AcctUnownerInfo::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void AcctUnownerInfo::prepareSQL()
{
    stmt->setString(1,acct_unowner_info.m_acc_nbr);
    stmt->setNumber(2,acct_unowner_info.m_item_source_id);
    stmt->setNumber(3,acct_unowner_info.m_acct_item_type_id);
    stmt->setString(4,acct_unowner_info.m_region_code);
    stmt->setNumber(5,acct_unowner_info.m_unowner_fee);
    stmt->setString(6,acct_unowner_info.m_state);
}

