#include "ZtOprLog.hh"

string ZtOprLog::insSQL="INSERT INTO ZT_OPR_LOG(STAFF_ID,STAFF_ORG_ID,LOGIN_ACCEPT,ACCT_ID,ZT_METHOD,SERV_ID,CYCLE_FLAG,BILLING_CYCLE_ID,ACC_NBR,REGION_ID,ACCT_NAME,SHOULD_PAY,FAVOUR_FEE,PAYED_PREPAY,PAYED_LATER,PREPAY_FEE,AMOUNT,DELAY_RATE,DELAY_FEE,OTHER_FEE,SHOULD_FEE,PAYMENT_ID,BILL_FLAG,STATUS,STATUS_FLAG,STATUS_TIME,INSERT_TIME,RESV,NEW_STATUS,OPERATE_TIME,NOTE,SYN_ID)VALUES (:STAFF_ID,:STAFF_ORG_ID,:LOGIN_ACCEPT,:ACCT_ID,:ZT_METHOD,:SERV_ID,:CYCLE_FLAG,:BILLING_CYCLE_ID,:ACC_NBR,:REGION_ID,:ACCT_NAME,:SHOULD_PAY,:FAVOUR_FEE,:PAYED_PREPAY,:PAYED_LATER,:PREPAY_FEE,:AMOUNT,:DELAY_RATE,:DELAY_FEE,:OTHER_FEE,:SHOULD_FEE,:PAYMENT_ID,:BILL_FLAG,:STATUS,:STATUS_FLAG,SYSDATE,SYSDATE,:RESV,:NEW_STATUS,SYSDATE,:NOTE,:SYN_ID)";

void ZtOprLog::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void ZtOprLog::prepareSQL()
{
    stmt->setNumber(1,zt_opr_log.m_staff_id);
    stmt->setNumber(2,zt_opr_log.m_staff_org_id);
    stmt->setNumber(3,zt_opr_log.m_login_accept);
    stmt->setNumber(4,zt_opr_log.m_acct_id);
    stmt->setString(5,zt_opr_log.m_zt_method);
    stmt->setNumber(6,zt_opr_log.m_serv_id);
    stmt->setString(7,zt_opr_log.m_cycle_flag);
    stmt->setNumber(8,zt_opr_log.m_billing_cycle_id);
    stmt->setString(9,zt_opr_log.m_acc_nbr);
    stmt->setNumber(10,zt_opr_log.m_region_id);
    stmt->setString(11,zt_opr_log.m_acct_name);
    stmt->setNumber(12,zt_opr_log.m_should_pay);
    stmt->setNumber(13,zt_opr_log.m_favour_fee);
    stmt->setNumber(14,zt_opr_log.m_payed_prepay);
    stmt->setNumber(15,zt_opr_log.m_payed_later);
    stmt->setNumber(16,zt_opr_log.m_prepay_fee);
    stmt->setNumber(17,zt_opr_log.m_amount);
    stmt->setNumber(18,zt_opr_log.m_delay_rate);
    stmt->setNumber(19,zt_opr_log.m_delay_fee);
    stmt->setNumber(20,zt_opr_log.m_other_fee);
    stmt->setNumber(21,zt_opr_log.m_should_fee);
    stmt->setNumber(22,zt_opr_log.m_payment_id);
    stmt->setString(23,zt_opr_log.m_bill_flag);
    stmt->setString(24,zt_opr_log.m_status);
    stmt->setString(25,zt_opr_log.m_status_flag);
    stmt->setString(26,zt_opr_log.m_resv);
    stmt->setString(27,zt_opr_log.m_new_status);
    stmt->setString(28,zt_opr_log.m_note);
    stmt->setNumber(29,zt_opr_log.m_syn_id);
}

