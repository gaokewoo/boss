#include "SendFeeLogHis.hh"

string SendFeeLogHis::insSQL="INSERT INTO SEND_FEE_LOG_HIS(SEND_LOG_ID,ACCT_ID,PAY_MONEY,SEND_MONEY,SEND_FLAG,STAFF_ID,OP_TIME,OP_NOTE,ACC_NBR,HIS_DATE,HIS_STAFF_ID,HIS_OPTSN)VALUES (:SEND_LOG_ID,:ACCT_ID,:PAY_MONEY,:SEND_MONEY,:SEND_FLAG,:STAFF_ID,SYSDATE,:OP_NOTE,:ACC_NBR,SYSDATE,:HIS_STAFF_ID,:HIS_OPTSN)";

void SendFeeLogHis::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void SendFeeLogHis::prepareSQL()
{
    stmt->setNumber(1,send_fee_log_his.m_send_log_id);
    stmt->setNumber(2,send_fee_log_his.m_acct_id);
    stmt->setNumber(3,send_fee_log_his.m_pay_money);
    stmt->setNumber(4,send_fee_log_his.m_send_money);
    stmt->setString(5,send_fee_log_his.m_send_flag);
    stmt->setNumber(6,send_fee_log_his.m_staff_id);
    stmt->setString(7,send_fee_log_his.m_op_note);
    stmt->setString(8,send_fee_log_his.m_acc_nbr);
    stmt->setNumber(9,send_fee_log_his.m_his_staff_id);
    stmt->setNumber(10,send_fee_log_his.m_his_optsn);
}

