#include "TransLog.hh"

string TransLog::insSQL="INSERT INTO TRANS_LOG(AGT_ACCEPT,PAY_ID,AGT_CODE,AGT_DATE,ACC_NBR,STAFF_ID,OP_CODE,OP_TIME,OP_MONEY,UNPAY_FLAG,REPAY_FLAG,COLLATE_FLAG,COLLATE_TIME,BAND_ID,PAYMENT_METHOD,ACNT_CODE)VALUES (:AGT_ACCEPT,:PAY_ID,:AGT_CODE,SYSDATE,:ACC_NBR,:STAFF_ID,:OP_CODE,SYSDATE,:OP_MONEY,:UNPAY_FLAG,:REPAY_FLAG,:COLLATE_FLAG,SYSDATE,:BAND_ID,:PAYMENT_METHOD,:ACNT_CODE)";

void TransLog::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void TransLog::prepareSQL()
{
    stmt->setString(1,trans_log.m_agt_accept);
    stmt->setNumber(2,trans_log.m_pay_id);
    stmt->setString(3,trans_log.m_agt_code);
    stmt->setString(4,trans_log.m_acc_nbr);
    stmt->setNumber(5,trans_log.m_staff_id);
    stmt->setString(6,trans_log.m_op_code);
    stmt->setNumber(7,trans_log.m_op_money);
    stmt->setString(8,trans_log.m_unpay_flag);
    stmt->setString(9,trans_log.m_repay_flag);
    stmt->setString(10,trans_log.m_collate_flag);
    stmt->setNumber(11,trans_log.m_band_id);
    stmt->setNumber(12,trans_log.m_payment_method);
    stmt->setString(13,trans_log.m_acnt_code);
}

