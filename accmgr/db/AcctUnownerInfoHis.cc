#include "AcctUnownerInfoHis.hh"

string AcctUnownerInfoHis::insSQL="INSERT INTO ACCT_UNOWNER_INFO_HIS(ACC_NBR,ITEM_SOURCE_ID,ACCT_ITEM_TYPE_ID,REGION_CODE,UNOWNER_FEE,INSERT_TIME,STATE,STATE_DATE)VALUES (:ACC_NBR,:ITEM_SOURCE_ID,:ACCT_ITEM_TYPE_ID,:REGION_CODE,:UNOWNER_FEE,SYSDATE,:STATE,SYSDATE)";

void AcctUnownerInfoHis::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void AcctUnownerInfoHis::prepareSQL()
{
    stmt->setString(1,acct_unowner_info_his.m_acc_nbr);
    stmt->setNumber(2,acct_unowner_info_his.m_item_source_id);
    stmt->setNumber(3,acct_unowner_info_his.m_acct_item_type_id);
    stmt->setString(4,acct_unowner_info_his.m_region_code);
    stmt->setNumber(5,acct_unowner_info_his.m_unowner_fee);
    stmt->setString(6,acct_unowner_info_his.m_state);
}

