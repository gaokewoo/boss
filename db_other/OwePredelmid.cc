#include "OwePredelmid.hh"

string OwePredelmid::insSQL="INSERT INTO OWE_PREDELMID(LOGIN_ACCEPT,SERV_ID,ACC_NBR,ATTR_CODE,REGION_ID,STATE_NAME,GRADE_NAME,BAND_NAME,OFFER_COMMENTS,REGION_NAME,DISTRICT_NAME,IS_VALID,RUN_TIME,OWE_FEE,PREPAY_FEE,ACCT_ID,ACCT_NAME,CUST_ID,CUST_NAME,STAFF_ID,OP_CODE,OPEN_TIME,RESV)VALUES (:LOGIN_ACCEPT,:SERV_ID,:ACC_NBR,:ATTR_CODE,:REGION_ID,:STATE_NAME,:GRADE_NAME,:BAND_NAME,:OFFER_COMMENTS,:REGION_NAME,:DISTRICT_NAME,:IS_VALID,SYSDATE,:OWE_FEE,:PREPAY_FEE,:ACCT_ID,:ACCT_NAME,:CUST_ID,:CUST_NAME,:STAFF_ID,:OP_CODE,SYSDATE,:RESV)";

void OwePredelmid::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void OwePredelmid::prepareSQL()
{
    stmt->setNumber(1,owe_predelmid.m_login_accept);
    stmt->setNumber(2,owe_predelmid.m_serv_id);
    stmt->setString(3,owe_predelmid.m_acc_nbr);
    stmt->setString(4,owe_predelmid.m_attr_code);
    stmt->setNumber(5,owe_predelmid.m_region_id);
    stmt->setString(6,owe_predelmid.m_state_name);
    stmt->setString(7,owe_predelmid.m_grade_name);
    stmt->setString(8,owe_predelmid.m_band_name);
    stmt->setString(9,owe_predelmid.m_offer_comments);
    stmt->setString(10,owe_predelmid.m_region_name);
    stmt->setString(11,owe_predelmid.m_district_name);
    stmt->setString(12,owe_predelmid.m_is_valid);
    stmt->setNumber(13,owe_predelmid.m_owe_fee);
    stmt->setNumber(14,owe_predelmid.m_prepay_fee);
    stmt->setNumber(15,owe_predelmid.m_acct_id);
    stmt->setString(16,owe_predelmid.m_acct_name);
    stmt->setNumber(17,owe_predelmid.m_cust_id);
    stmt->setString(18,owe_predelmid.m_cust_name);
    stmt->setNumber(19,owe_predelmid.m_staff_id);
    stmt->setString(20,owe_predelmid.m_op_code);
    stmt->setString(21,owe_predelmid.m_resv);
}

