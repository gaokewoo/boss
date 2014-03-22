#include "BillInterface.hh"

string BillInterface::insSQL="INSERT INTO BILL_INTERFACE(PAYMENT_ID,ACCT_ID,SERV_ID,OP_CODE,STAFF_ID,PAYMENT_METHOD,PAYMENT_DATE,ONLINE_FLAG,STATE,STATE_DATE,OP_NOTE,BILL_BEG_YM,BILL_END_YM,BILL_MONTH_FLAG,SERV_PAY_FLAG)VALUES (:PAYMENT_ID,:ACCT_ID,:SERV_ID,:OP_CODE,:STAFF_ID,:PAYMENT_METHOD,SYSDATE,:ONLINE_FLAG,:STATE,SYSDATE,:OP_NOTE,:BILL_BEG_YM,:BILL_END_YM,:BILL_MONTH_FLAG,:SERV_PAY_FLAG)";

void BillInterface::insertData()
{
    type=INSERT;
    setSQL(insSQL);
    executeUpdate();
}

void BillInterface::deleteBillInterfaceByPaymentId(long payment_id)
{
    type=DELETE;
    m_payment_id = payment_id;

    setSQL("INSERT INTO BILL_INTERFACE_HIS"
                "(PAYMENT_ID,ACCT_ID,SERV_ID,OP_CODE,STAFF_ID,PAYMENT_METHOD,"
                "PAYMENT_DATE,ONLINE_FLAG,STATE,STATE_DATE,OP_NOTE,HIS_DATE,"
                "BILL_BEG_YM,BILL_END_YM,BILL_MONTH_FLAG,SERV_PAY_FLAG "
                "SELECT PAYMENT_ID,ACCT_ID,SERV_ID,OP_CODE,STAFF_ID,PAYMENT_METHOD,"
                "PAYMENT_DATE,ONLINE_FLAG,STATE,STATE_DATE,OP_NOTE,SYSDATE,"
                "BILL_BEG_YM,BILL_END_YM,BILL_MONTH_FLAG,SERV_PAY_FLAG "
                "FROM BILL_INTERFACE WHERE PAYMENT_ID=:PAYMENT_ID");
    executeUpdate();

    setSQL("DELETE FROM BILL_INTERFACE WHERE PAYMENT_ID=:PAYMENT_ID");
    executeUpdate();
}

vector<ST_BILL_INTERFACE> BillInterface::loadAllData()
{
    type=SELECT_ALL;
    setSQL("SELECT PAYMENT_ID,ACCT_ID,SERV_ID,OP_CODE,STAFF_ID,PAYMENT_METHOD,TO_CHAR(PAYMENT_DATE,'YYYYMMDDHH24MISS'),ONLINE_FLAG,STATE,TO_CHAR(STATE_DATE,'YYYYMMDDHH24MISS'),OP_NOTE,BILL_BEG_YM,BILL_END_YM,BILL_MONTH_FLAG,SERV_PAY_FLAG FROM BILL_INTERFACE");
    executeQuery();

    return v_data;
}

void BillInterface::doParse()
{
    bill_interface.m_payment_id = (long)rset->getNumber(1);
    bill_interface.m_acct_id = (long)rset->getNumber(2);
    bill_interface.m_serv_id = (long)rset->getNumber(3);
    bill_interface.m_op_code = rset->getString(4);
    bill_interface.m_staff_id = (long)rset->getNumber(5);
    bill_interface.m_payment_method = (long)rset->getNumber(6);
    bill_interface.m_payment_date = rset->getString(7);
    bill_interface.m_online_flag = (long)rset->getNumber(8);
    bill_interface.m_state = rset->getString(9);
    bill_interface.m_state_date = rset->getString(10);
    bill_interface.m_op_note = rset->getString(11);
    bill_interface.m_bill_beg_ym = (long)rset->getNumber(12);
    bill_interface.m_bill_end_ym = (long)rset->getNumber(13);
    bill_interface.m_bill_month_flag = rset->getString(14);
    bill_interface.m_serv_pay_flag = (long)rset->getNumber(15);

    v_data.push_back(bill_interface);
}

void BillInterface::prepareSQL()
{
    if (type == INSERT)
    {
        stmt->setNumber(1,bill_interface.m_payment_id);
        stmt->setNumber(2,bill_interface.m_acct_id);
        stmt->setNumber(3,bill_interface.m_serv_id);
        stmt->setString(4,bill_interface.m_op_code);
        stmt->setNumber(5,bill_interface.m_staff_id);
        stmt->setNumber(6,bill_interface.m_payment_method);
        stmt->setNumber(7,bill_interface.m_online_flag);
        stmt->setString(8,bill_interface.m_state);
        stmt->setString(9,bill_interface.m_op_note);
        stmt->setNumber(10,bill_interface.m_bill_beg_ym);
        stmt->setNumber(11,bill_interface.m_bill_end_ym);
        stmt->setString(12,bill_interface.m_bill_month_flag);
        stmt->setNumber(13,bill_interface.m_serv_pay_flag);
    }
    else if (type == DELETE)
    {
        stmt->setNumber(1,m_payment_id);
    }
}

