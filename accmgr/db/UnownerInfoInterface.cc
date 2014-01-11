#include "UnownerInfoInterface.hh"

string UnownerInfoInterface::insSQL="INSERT INTO UNOWNER_INFO_INTERFACE(ORDER_ID,COMMAND_ID,HLR_CODE,COMMAND_CODE,COMMAND_ORDER,SERV_ID,BELONG_CODE,SM_CODE,ACC_NBR,NEW_ACC_NBR,IMSI_NO,NEW_IMSI,OTHER_CHAR,OP_CODE,TOTAL_DATE,OP_TIME,STAFF_CODE,ORG_CODE,LOGIN_ACCEPT,REQUEST_TIME,BUSINESS_STATUS,SEND_STATUS,SEND_TIME,GROUP_ID,ORG_ID,SUCC_FLAG,ERR_MSG,CITY_ID)VALUES (:ORDER_ID,:COMMAND_ID,:HLR_CODE,:COMMAND_CODE,:COMMAND_ORDER,:SERV_ID,:BELONG_CODE,:SM_CODE,:ACC_NBR,:NEW_ACC_NBR,:IMSI_NO,:NEW_IMSI,:OTHER_CHAR,:OP_CODE,:TOTAL_DATE,SYSDATE,:STAFF_CODE,:ORG_CODE,:LOGIN_ACCEPT,SYSDATE,:BUSINESS_STATUS,:SEND_STATUS,SYSDATE,:GROUP_ID,:ORG_ID,:SUCC_FLAG,:ERR_MSG,:CITY_ID)";

void UnownerInfoInterface::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void UnownerInfoInterface::prepareSQL()
{
    stmt->setString(1,unowner_info_interface.m_order_id);
    stmt->setNumber(2,unowner_info_interface.m_command_id);
    stmt->setString(3,unowner_info_interface.m_hlr_code);
    stmt->setString(4,unowner_info_interface.m_command_code);
    stmt->setNumber(5,unowner_info_interface.m_command_order);
    stmt->setNumber(6,unowner_info_interface.m_serv_id);
    stmt->setString(7,unowner_info_interface.m_belong_code);
    stmt->setString(8,unowner_info_interface.m_sm_code);
    stmt->setString(9,unowner_info_interface.m_acc_nbr);
    stmt->setString(10,unowner_info_interface.m_new_acc_nbr);
    stmt->setString(11,unowner_info_interface.m_imsi_no);
    stmt->setString(12,unowner_info_interface.m_new_imsi);
    stmt->setString(13,unowner_info_interface.m_other_char);
    stmt->setString(14,unowner_info_interface.m_op_code);
    stmt->setNumber(15,unowner_info_interface.m_total_date);
    stmt->setString(16,unowner_info_interface.m_staff_code);
    stmt->setString(17,unowner_info_interface.m_org_code);
    stmt->setNumber(18,unowner_info_interface.m_login_accept);
    stmt->setString(19,unowner_info_interface.m_business_status);
    stmt->setString(20,unowner_info_interface.m_send_status);
    stmt->setString(21,unowner_info_interface.m_group_id);
    stmt->setString(22,unowner_info_interface.m_org_id);
    stmt->setString(23,unowner_info_interface.m_succ_flag);
    stmt->setString(24,unowner_info_interface.m_err_msg);
    stmt->setString(25,unowner_info_interface.m_city_id);
}

