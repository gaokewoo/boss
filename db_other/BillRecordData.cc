#include "BillRecordData.hh"

string BillRecordData::insSQL="INSERT INTO BILL_RECORD_DATA(SERV_ID,ACC_NBR,ACCT_ID,CUST_ID,BILLING_CYCLE_ID,BILL_RECORD_ID,BILL_RECORD_NAME,SHOULD_PAY,FAVOUR_FEE,BILL_POST_METHOD,REGION_ID,STAFF_ID,INSERT_TIME)VALUES (:SERV_ID,:ACC_NBR,:ACCT_ID,:CUST_ID,:BILLING_CYCLE_ID,:BILL_RECORD_ID,:BILL_RECORD_NAME,:SHOULD_PAY,:FAVOUR_FEE,:BILL_POST_METHOD,:REGION_ID,:STAFF_ID,SYSDATE)";

void BillRecordData::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void BillRecordData::prepareSQL()
{
    stmt->setNumber(1,bill_record_data.m_serv_id);
    stmt->setString(2,bill_record_data.m_acc_nbr);
    stmt->setNumber(3,bill_record_data.m_acct_id);
    stmt->setNumber(4,bill_record_data.m_cust_id);
    stmt->setNumber(5,bill_record_data.m_billing_cycle_id);
    stmt->setNumber(6,bill_record_data.m_bill_record_id);
    stmt->setString(7,bill_record_data.m_bill_record_name);
    stmt->setNumber(8,bill_record_data.m_should_pay);
    stmt->setNumber(9,bill_record_data.m_favour_fee);
    stmt->setString(10,bill_record_data.m_bill_post_method);
    stmt->setNumber(11,bill_record_data.m_region_id);
    stmt->setNumber(12,bill_record_data.m_staff_id);
}

