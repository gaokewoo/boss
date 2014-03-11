#include "BillUnownerInfoHis.hh"

string BillUnownerInfoHis::insSQL="INSERT INTO BILL_UNOWNER_INFO_HIS(BILL_UNOWNER_ID,ACC_NBR,UNOWNER_TYPE,REGION_CODE,IMSI_NO,UNOWNER_FEE,UNOWNER_COUNT,UNOWNER_BEGIN_TIME,UNOWNER_LAST_TIME,INSERT_TIME,STATE,STATE_DATE)VALUES (:BILL_UNOWNER_ID,:ACC_NBR,:UNOWNER_TYPE,:REGION_CODE,:IMSI_NO,:UNOWNER_FEE,:UNOWNER_COUNT,SYSDATE,SYSDATE,SYSDATE,:STATE,SYSDATE)";

void BillUnownerInfoHis::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void BillUnownerInfoHis::prepareSQL()
{
    stmt->setNumber(1,bill_unowner_info_his.m_bill_unowner_id);
    stmt->setString(2,bill_unowner_info_his.m_acc_nbr);
    stmt->setString(3,bill_unowner_info_his.m_unowner_type);
    stmt->setString(4,bill_unowner_info_his.m_region_code);
    stmt->setString(5,bill_unowner_info_his.m_imsi_no);
    stmt->setNumber(6,bill_unowner_info_his.m_unowner_fee);
    stmt->setNumber(7,bill_unowner_info_his.m_unowner_count);
    stmt->setString(8,bill_unowner_info_his.m_state);
}

