#include "TifOweNotification.hh"

string TifOweNotification::insSQL="INSERT INTO TIF_OWE_NOTIFICATION(INTID,ACCT_ID,SERV_TYPE_ID,AREA_CODE,SERV_NBR,ACTION_TYPE,SUM_CHARGE,MONTH_DETAIL,ACTION_TIME,START_DATE,END_DATE,CREATED_DATE,TSUCCCNT,DSUCCCNT,TFAILCNT,DFAILCNT,NTSUCCCNT,NDSUCCCNT,NTFAILCNT,NDFAILCNT,NFAILREASON,FIRST_SUCC_DATE,NCJJFFLAG,UPDATEFLAG,UPDATETIME_CC,UPDATETIME_KF,DO_FLAG)VALUES (:INTID,:ACCT_ID,:SERV_TYPE_ID,:AREA_CODE,:SERV_NBR,:ACTION_TYPE,:SUM_CHARGE,:MONTH_DETAIL,:ACTION_TIME,SYSDATE,SYSDATE,SYSDATE,:TSUCCCNT,:DSUCCCNT,:TFAILCNT,:DFAILCNT,:NTSUCCCNT,:NDSUCCCNT,:NTFAILCNT,:NDFAILCNT,:NFAILREASON,SYSDATE,:NCJJFFLAG,:UPDATEFLAG,SYSDATE,SYSDATE,:DO_FLAG)";

void TifOweNotification::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void TifOweNotification::prepareSQL()
{
    stmt->setNumber(1,tif_owe_notification.m_intid);
    stmt->setString(2,tif_owe_notification.m_acct_id);
    stmt->setString(3,tif_owe_notification.m_serv_type_id);
    stmt->setString(4,tif_owe_notification.m_area_code);
    stmt->setString(5,tif_owe_notification.m_serv_nbr);
    stmt->setNumber(6,tif_owe_notification.m_action_type);
    stmt->setNumber(7,tif_owe_notification.m_sum_charge);
    stmt->setString(8,tif_owe_notification.m_month_detail);
    stmt->setString(9,tif_owe_notification.m_action_time);
    stmt->setNumber(10,tif_owe_notification.m_tsucccnt);
    stmt->setNumber(11,tif_owe_notification.m_dsucccnt);
    stmt->setNumber(12,tif_owe_notification.m_tfailcnt);
    stmt->setNumber(13,tif_owe_notification.m_dfailcnt);
    stmt->setNumber(14,tif_owe_notification.m_ntsucccnt);
    stmt->setNumber(15,tif_owe_notification.m_ndsucccnt);
    stmt->setNumber(16,tif_owe_notification.m_ntfailcnt);
    stmt->setNumber(17,tif_owe_notification.m_ndfailcnt);
    stmt->setNumber(18,tif_owe_notification.m_nfailreason);
    stmt->setNumber(19,tif_owe_notification.m_ncjjfflag);
    stmt->setNumber(20,tif_owe_notification.m_updateflag);
    stmt->setNumber(21,tif_owe_notification.m_do_flag);
}

