#include "StaffOpr.hh"

string StaffOpr::insSQL="INSERT INTO STAFF_OPR(LOGIN_ACCEPT,TOTAL_DATE,OP_CODE,PAYMENT_METHOD,PAY_MONEY,BAND_ID,SERV_ID,ACC_NBR,OP_TIME,OP_NOTE,IP_ADDR,STAFF_ORG_ID,NBR_ORG_ID,STAFF_ID)VALUES (:LOGIN_ACCEPT,:TOTAL_DATE,:OP_CODE,:PAYMENT_METHOD,:PAY_MONEY,:BAND_ID,:SERV_ID,:ACC_NBR,SYSDATE,:OP_NOTE,:IP_ADDR,:STAFF_ORG_ID,:NBR_ORG_ID,:STAFF_ID)";

void StaffOpr::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void StaffOpr::prepareSQL()
{
    stmt->setNumber(1,staff_opr.m_login_accept);
    stmt->setNumber(2,staff_opr.m_total_date);
    stmt->setString(3,staff_opr.m_op_code);
    stmt->setNumber(4,staff_opr.m_payment_method);
    stmt->setNumber(5,staff_opr.m_pay_money);
    stmt->setNumber(6,staff_opr.m_band_id);
    stmt->setNumber(7,staff_opr.m_serv_id);
    stmt->setString(8,staff_opr.m_acc_nbr);
    stmt->setString(9,staff_opr.m_op_note);
    stmt->setString(10,staff_opr.m_ip_addr);
    stmt->setNumber(11,staff_opr.m_staff_org_id);
    stmt->setNumber(12,staff_opr.m_nbr_org_id);
    stmt->setNumber(13,staff_opr.m_staff_id);
}

