#include "BillInterfaceHis.hh"

string BillInterfaceHis::insSQL="INSERT INTO BILL_INTERFACE_HIS(PAYMENT_ID,ACCT_ID,SERV_ID,OP_CODE,STAFF_ID,PAYMENT_METHOD,PAYMENT_DATE,ONLINE_FLAG,STATE,STATE_DATE,OP_NOTE,BILL_BEG_YM,BILL_END_YM,HIS_DATE,BILL_MONTH_FLAG,SERV_PAY_FLAG)VALUES (:PAYMENT_ID,:ACCT_ID,:SERV_ID,:OP_CODE,:STAFF_ID,:PAYMENT_METHOD,SYSDATE,:ONLINE_FLAG,:STATE,SYSDATE,:OP_NOTE,:BILL_BEG_YM,:BILL_END_YM,SYSDATE,:BILL_MONTH_FLAG,:SERV_PAY_FLAG)";

void BillInterfaceHis::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void BillInterfaceHis::prepareSQL()
{
    stmt->setNumber(1,bill_interface_his.m_payment_id);
    stmt->setNumber(2,bill_interface_his.m_acct_id);
    stmt->setNumber(3,bill_interface_his.m_serv_id);
    stmt->setString(4,bill_interface_his.m_op_code);
    stmt->setNumber(5,bill_interface_his.m_staff_id);
    stmt->setNumber(6,bill_interface_his.m_payment_method);
    stmt->setNumber(7,bill_interface_his.m_online_flag);
    stmt->setString(8,bill_interface_his.m_state);
    stmt->setString(9,bill_interface_his.m_op_note);
    stmt->setNumber(10,bill_interface_his.m_bill_beg_ym);
    stmt->setNumber(11,bill_interface_his.m_bill_end_ym);
    stmt->setString(12,bill_interface_his.m_bill_month_flag);
    stmt->setNumber(13,bill_interface_his.m_serv_pay_flag);
}

