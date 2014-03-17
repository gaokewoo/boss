#include "SendFeeLog.hh"

string SendFeeLog::insSQL="INSERT INTO SEND_FEE_LOG(SEND_LOG_ID,ACCT_ID,PAY_MONEY,SEND_MONEY,SEND_FLAG,STAFF_ID,OP_TIME,OP_NOTE,ACC_NBR)VALUES (:SEND_LOG_ID,:ACCT_ID,:PAY_MONEY,:SEND_MONEY,:SEND_FLAG,:STAFF_ID,SYSDATE,:OP_NOTE,:ACC_NBR)";

void SendFeeLog::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void SendFeeLog::prepareSQL()
{
    stmt->setNumber(1,send_fee_log.m_send_log_id);
    stmt->setNumber(2,send_fee_log.m_acct_id);
    stmt->setNumber(3,send_fee_log.m_pay_money);
    stmt->setNumber(4,send_fee_log.m_send_money);
    stmt->setString(5,send_fee_log.m_send_flag);
    stmt->setNumber(6,send_fee_log.m_staff_id);
    stmt->setString(7,send_fee_log.m_op_note);
    stmt->setString(8,send_fee_log.m_acc_nbr);
}

