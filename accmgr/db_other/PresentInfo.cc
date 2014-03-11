#include "PresentInfo.hh"

string PresentInfo::insSQL="INSERT INTO PRESENT_INFO(PRESENT_ID,SERV_ID,ACC_NBR,ACCT_ID,CUST_ID,REGION_ID,BAND_ID,STAFF_ID,PRESENT_RULE_ID,PRESENT_CODE,PRESENT_TYPE,PRESENT_MONEY,PRESENT_MONTH,PRESENT_BALANCE_TYPE_ID,BALANCE,PRESENT_RATE,MONTH_FEE,FAVOUR_FEE,EFF_DATE,EXP_DATE,STATE,STATE_DATE,PRESENT_DESC,UPDATE_STAFF_ID,UPDATE_STATE_DATE)VALUES (:PRESENT_ID,:SERV_ID,:ACC_NBR,:ACCT_ID,:CUST_ID,:REGION_ID,:BAND_ID,:STAFF_ID,:PRESENT_RULE_ID,:PRESENT_CODE,:PRESENT_TYPE,:PRESENT_MONEY,:PRESENT_MONTH,:PRESENT_BALANCE_TYPE_ID,:BALANCE,:PRESENT_RATE,:MONTH_FEE,:FAVOUR_FEE,SYSDATE,SYSDATE,:STATE,SYSDATE,:PRESENT_DESC,:UPDATE_STAFF_ID,SYSDATE)";

void PresentInfo::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void PresentInfo::prepareSQL()
{
    stmt->setNumber(1,present_info.m_present_id);
    stmt->setNumber(2,present_info.m_serv_id);
    stmt->setString(3,present_info.m_acc_nbr);
    stmt->setNumber(4,present_info.m_acct_id);
    stmt->setNumber(5,present_info.m_cust_id);
    stmt->setNumber(6,present_info.m_region_id);
    stmt->setNumber(7,present_info.m_band_id);
    stmt->setNumber(8,present_info.m_staff_id);
    stmt->setNumber(9,present_info.m_present_rule_id);
    stmt->setString(10,present_info.m_present_code);
    stmt->setString(11,present_info.m_present_type);
    stmt->setNumber(12,present_info.m_present_money);
    stmt->setNumber(13,present_info.m_present_month);
    stmt->setNumber(14,present_info.m_present_balance_type_id);
    stmt->setNumber(15,present_info.m_balance);
    stmt->setNumber(16,present_info.m_present_rate);
    stmt->setNumber(17,present_info.m_month_fee);
    stmt->setNumber(18,present_info.m_favour_fee);
    stmt->setString(19,present_info.m_state);
    stmt->setString(20,present_info.m_present_desc);
    stmt->setNumber(21,present_info.m_update_staff_id);
}

