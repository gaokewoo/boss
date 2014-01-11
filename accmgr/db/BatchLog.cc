#include "BatchLog.hh"

string BatchLog::insSQL="INSERT INTO BATCH_LOG(LOGIN_ACCEPT,OP_CODE,STAFF_ID,BEGIN_TIME,END_TIME,DEAL_NUM,SUCC_NUM,ERR_NO,ERR_MSG)VALUES (:LOGIN_ACCEPT,:OP_CODE,:STAFF_ID,SYSDATE,SYSDATE,:DEAL_NUM,:SUCC_NUM,:ERR_NO,:ERR_MSG)";

void BatchLog::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void BatchLog::prepareSQL()
{
    stmt->setNumber(1,batch_log.m_login_accept);
    stmt->setString(2,batch_log.m_op_code);
    stmt->setNumber(3,batch_log.m_staff_id);
    stmt->setNumber(4,batch_log.m_deal_num);
    stmt->setNumber(5,batch_log.m_succ_num);
    stmt->setString(6,batch_log.m_err_no);
    stmt->setString(7,batch_log.m_err_msg);
}

