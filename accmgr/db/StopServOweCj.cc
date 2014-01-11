#include "StopServOweCj.hh"

string StopServOweCj::insSQL="INSERT INTO STOP_SERV_OWE_CJ(SERV_ID,MIN_OWE_YM,MAX_OWE_YM,OWE_FEE,ACCT_ID,ACC_NBR,BELONG_CODE,PRODUCT_ID,MONTH_DETAIL,OFFER_ID,USER_FLAG,ACTION_TIME)VALUES (:SERV_ID,:MIN_OWE_YM,:MAX_OWE_YM,:OWE_FEE,:ACCT_ID,:ACC_NBR,:BELONG_CODE,:PRODUCT_ID,:MONTH_DETAIL,:OFFER_ID,:USER_FLAG,:ACTION_TIME)";

void StopServOweCj::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void StopServOweCj::prepareSQL()
{
    stmt->setNumber(1,stop_serv_owe_cj.m_serv_id);
    stmt->setNumber(2,stop_serv_owe_cj.m_min_owe_ym);
    stmt->setNumber(3,stop_serv_owe_cj.m_max_owe_ym);
    stmt->setNumber(4,stop_serv_owe_cj.m_owe_fee);
    stmt->setNumber(5,stop_serv_owe_cj.m_acct_id);
    stmt->setString(6,stop_serv_owe_cj.m_acc_nbr);
    stmt->setString(7,stop_serv_owe_cj.m_belong_code);
    stmt->setNumber(8,stop_serv_owe_cj.m_product_id);
    stmt->setString(9,stop_serv_owe_cj.m_month_detail);
    stmt->setNumber(10,stop_serv_owe_cj.m_offer_id);
    stmt->setString(11,stop_serv_owe_cj.m_user_flag);
    stmt->setString(12,stop_serv_owe_cj.m_action_time);
}

