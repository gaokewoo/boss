#include "BatchLogDet.hh"

string BatchLogDet::insSQL="INSERT INTO BATCH_LOG_DET(TOTAL_DATE,LOGIN_ACCEPT,OP_CODE,ACC_NBR,SERV_ID,BAND_ID,STAFF_ID,REGION_ID,OP_TIME,OP_FLAG,OP_NOTE,DATA1,NAME1,DATA2,NAME2,DATA3,NAME3,DATA4,NAME4,DATA5,NAME5)VALUES (:TOTAL_DATE,:LOGIN_ACCEPT,:OP_CODE,:ACC_NBR,:SERV_ID,:BAND_ID,:STAFF_ID,:REGION_ID,SYSDATE,:OP_FLAG,:OP_NOTE,:DATA1,:NAME1,:DATA2,:NAME2,:DATA3,:NAME3,:DATA4,:NAME4,:DATA5,:NAME5)";

void BatchLogDet::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void BatchLogDet::prepareSQL()
{
    stmt->setNumber(1,batch_log_det.m_total_date);
    stmt->setNumber(2,batch_log_det.m_login_accept);
    stmt->setString(3,batch_log_det.m_op_code);
    stmt->setString(4,batch_log_det.m_acc_nbr);
    stmt->setNumber(5,batch_log_det.m_serv_id);
    stmt->setNumber(6,batch_log_det.m_band_id);
    stmt->setNumber(7,batch_log_det.m_staff_id);
    stmt->setNumber(8,batch_log_det.m_region_id);
    stmt->setString(9,batch_log_det.m_op_flag);
    stmt->setString(10,batch_log_det.m_op_note);
    stmt->setNumber(11,batch_log_det.m_data1);
    stmt->setString(12,batch_log_det.m_name1);
    stmt->setNumber(13,batch_log_det.m_data2);
    stmt->setString(14,batch_log_det.m_name2);
    stmt->setNumber(15,batch_log_det.m_data3);
    stmt->setString(16,batch_log_det.m_name3);
    stmt->setNumber(17,batch_log_det.m_data4);
    stmt->setString(18,batch_log_det.m_name4);
    stmt->setNumber(19,batch_log_det.m_data5);
    stmt->setString(20,batch_log_det.m_name5);
}

