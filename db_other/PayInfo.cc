#include "PayInfo.hh"

string PayInfo::insSQL="INSERT INTO PAY_INFO(SERV_ORDER_ID,PAYINFO_ID,LOGIN_NO,OP_CODE,CONTRACT_NO,PHONE_NO,PAY_TYPE,FEE_TYPE,FEE_CODE,ACC_FEE_CODE,OUT_FEE_CODE,PAY_MONEY)VALUES (:SERV_ORDER_ID,:PAYINFO_ID,:LOGIN_NO,:OP_CODE,:CONTRACT_NO,:PHONE_NO,:PAY_TYPE,:FEE_TYPE,:FEE_CODE,:ACC_FEE_CODE,:OUT_FEE_CODE,:PAY_MONEY)";

void PayInfo::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void PayInfo::prepareSQL()
{
    stmt->setString(1,pay_info.m_serv_order_id);
    stmt->setNumber(2,pay_info.m_payinfo_id);
    stmt->setString(3,pay_info.m_login_no);
    stmt->setString(4,pay_info.m_op_code);
    stmt->setNumber(5,pay_info.m_contract_no);
    stmt->setString(6,pay_info.m_phone_no);
    stmt->setString(7,pay_info.m_pay_type);
    stmt->setString(8,pay_info.m_fee_type);
    stmt->setString(9,pay_info.m_fee_code);
    stmt->setString(10,pay_info.m_acc_fee_code);
    stmt->setString(11,pay_info.m_out_fee_code);
    stmt->setNumber(12,pay_info.m_pay_money);
}

